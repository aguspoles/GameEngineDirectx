#include "stdafx.h"
#include "Game.h"

//definimos un formato de modelo de vertices
#define CUSTOMFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_NORMAL | D3DFVF_TEX0)

struct Vertex
{
	FLOAT x, y, z, rhw;
	DWORD color;
};

Game::Game()
{
}


Game::~Game()
{
}

void Game::Run(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_     LPSTR    lpCmdLine,
	_In_     int       nCmdShow)
{
	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

		//Creamos la clase de la ventana
		WNDCLASSEX wcex;

		//Iniciamos sus valores en 0
		ZeroMemory(&wcex, sizeof(WNDCLASSEX));


		wcex.cbSize = sizeof(WNDCLASSEX); //Tama�o en bytes
		wcex.style = CS_HREDRAW | CS_VREDRAW; //Estilo de la ventana
		wcex.lpfnWndProc = WndProc; //Funcion de manejo de mensajes de ventana
		wcex.hInstance = hInstance; //Numero de instancia
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW); //Cursor del mouse
		wcex.hbrBackground = (HBRUSH)(COLOR_GRADIENTACTIVECAPTION + 1); //Color de fondo
		wcex.lpszClassName = L"GameWindowClass"; //Nombre del tipo (clase) de ventana

												 //Registro mi tipo de ventana en windows
		RegisterClassEx(&wcex);

		//Creo la ventana, recibiendo el numero de ventana
		HWND hWnd = CreateWindowEx(0, //Flags extra de estilo
			L"GameWindowClass", //Nombre del tipo de ventana a crear
			L"Game", //Titulo de la barra
			WS_OVERLAPPEDWINDOW, //Flags de estilos
			0, //X
			0, //Y
			640, //Ancho
			480, //Alto
			NULL, //Ventana padre
			NULL, //Menu
			hInstance, //Numero de proceso
			NULL); //Flags de multi ventana

		ShowWindow(hWnd, nCmdShow); //Muestro la ventana
		UpdateWindow(hWnd); //La actualizo para que se vea

							//Me comunico con directx por una interfaz, aca la creo
		LPDIRECT3D9 d3d = Direct3DCreate9(D3D_SDK_VERSION);

		//Creo los parametros de los buffers de dibujado (pantalla)
		D3DPRESENT_PARAMETERS d3dpp;
		ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));
		d3dpp.Windowed = true;
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3dpp.hDeviceWindow = hWnd;

		//Creo la interfaz con la placa de video
		LPDIRECT3DDEVICE9 dev;
		d3d->CreateDevice(D3DADAPTER_DEFAULT, //Cual placa de video
			D3DDEVTYPE_HAL, //Soft o hard
			hWnd, //Ventana
			D3DCREATE_HARDWARE_VERTEXPROCESSING, //Proceso de vertices por soft o hard
			&d3dpp, //Los parametros de buffers
			&dev); //El device que se crea


		Vertex vertexes[] =
		{
			{ 0.0f, 0.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(255,0,0) },
			{ 100.0f, 0.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(0,255,0) },
			{ 0.0f, 100.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(0,0,255) },
			{ 0.0f, 100.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(255,255,255) },
			//{ 50.0f, 100.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(0,0,255) },
		};

		WORD indexes[] =
		{
			0,3,2,0,1,3
		};

		//reservamos espacio en vram para guardar el modelo, utilizando el device q creamos antes
		LPDIRECT3DVERTEXBUFFER9 vb;
		dev->CreateVertexBuffer(4 * sizeof(Vertex),
			D3DUSAGE_WRITEONLY,//el uso q le vamos a dar
			CUSTOMFVF,
			D3DPOOL_MANAGED,//lo subimos a vram
			&vb,
			NULL);

		LPDIRECT3DINDEXBUFFER9 ib;
		dev->CreateIndexBuffer(
			6 * sizeof(WORD),
			D3DUSAGE_WRITEONLY,
			D3DFMT_INDEX16,
			D3DPOOL_MANAGED,
			&ib,
			NULL
		);

        //puntero a la memoria del vb en la vram
		VOID *data;
	    //compiamos el array de veritces q esta en la ram de la cpu 
		//a el puntero del vb en la vram, especificando cuantos 
		//bytes vamos a copiar
		vb->Lock(0, 0, &data, 0);
		memcpy(data, vertexes, 4 * sizeof(Vertex));
		vb->Unlock();

		ib->Lock(0, 0, &data, 0);
		memcpy(data, indexes, 6 * sizeof(WORD));
		ib->Unlock();


		while (true)
		{
			MSG msg;

			//Saco un mensaje de la cola de mensajes si es que hay
			//sino continuo
			while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}

			if (msg.message == WM_QUIT)
			{
				break;
			}

			//Actualizar
			//dev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 0, 0), 1.0F, 0);
			dev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 100, 0, 100), 1.0f, 0);
			//TODO: Dibujar
			dev->BeginScene();

			//especificamos el formato del vertice
			dev->SetFVF(CUSTOMFVF);

			//especificamos cual vb vamos a usar
			dev->SetStreamSource(0, vb, 0, sizeof(Vertex));

			//especificamos q indices vamos  a usar
			dev->SetIndices(ib);

			//esto apga el culling de la placa para ver si
			//nuestro modelo...
			//dev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

			//dibujamos 1 triangulo de dicho buffer
			dev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);
			dev->EndScene();
			dev->Present(NULL, NULL, NULL, NULL);

			ib->Release();
			vb->Release();
		}
		dev->Release();
		d3d->Release();
	}

	//Manejo de mensajes por ventana
	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		if (message == WM_DESTROY)
		{
			//Si destruyeron esta ventana (cerraron) le pido
			//a windows que cierre la app
			PostQuitMessage(0);
			return 0;
		}

		//Si no maneje el mensaje antes, hago el comportamiento por defecto
		return DefWindowProc(hWnd, message, wParam, lParam);
	}


