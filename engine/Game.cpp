#include "stdafx.h"
#include "Game.h"


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
		d3d->CreateDevice(D3DADAPTER_DEFAULT, //Cual placa de vido
			D3DDEVTYPE_HAL, //Soft o hard
			hWnd, //Ventana
			D3DCREATE_HARDWARE_VERTEXPROCESSING, //Proceso de vertices por soft o hard
			&d3dpp, //Los parametros de buffers
			&dev); //El device que se crea



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
			dev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 100, 0, 100), 1.0f, 0);
			dev->BeginScene();
			//TODO: Dibujar
			dev->EndScene();
			dev->Present(NULL, NULL, NULL, NULL);
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


