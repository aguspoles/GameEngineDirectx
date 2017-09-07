#include "stdafx.h"
#include "Game.h"

float Game::_deltaTime = 0;

Game::Game() : _tileMap(NULL)
{
	_camera = new Camera();
}

Game::~Game()
{
	if (_camera)
	{
	    delete _camera;
		_camera = NULL;
	}
	if (_tileMap)
	{
		delete _tileMap;
		_tileMap = NULL;
	}
	for each(MeshRenderer* entitie in _entities)
	{
		if (entitie)
		{
			delete entitie;
			entitie = NULL;
		}
	}
	for each(Material* material in _materials)
	{
		if (material)
		{
			delete material;
			material = NULL;
		}
	}
	for each(Model* model in _models)
	{
		if (model)
		{
			delete model;
			model = NULL;
		}
	}
	_entities.clear();
	_materials.clear();
	_models.clear();
	Device->Release();
	d3d->Release();
}

void Game::InitD3D(_In_ HINSTANCE hInstance, _In_ int nCmdShow)
{
	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	//Creamos la clase de la ventana
	WNDCLASSEX wcex;

	//Iniciamos sus valores en 0
	ZeroMemory(&wcex, sizeof(WNDCLASSEX));

	wcex.cbSize = sizeof(WNDCLASSEX); //Tamaño en bytes
	wcex.style = CS_HREDRAW | CS_VREDRAW; //Estilo de la ventana
	wcex.lpfnWndProc = WndProc; //Funcion de manejo de mensajes de ventana
	wcex.hInstance = hInstance; //Numero de instancia
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW); //Cursor del mouse
	wcex.hbrBackground = (HBRUSH)(COLOR_GRADIENTACTIVECAPTION + 1); //Color de fondo
	wcex.lpszClassName = L"GameWindowClass"; //Nombre del tipo (clase) de ventana

	RegisterClassEx(&wcex);  //Registro mi tipo de ventana en windows

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
	d3d = Direct3DCreate9(D3D_SDK_VERSION);

	//Creo los parametros de los buffers de dibujado (pantalla)
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));
	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hWnd;

	//Creo la interfaz con la placa de video
	d3d->CreateDevice(D3DADAPTER_DEFAULT, //Cual placa de video
		D3DDEVTYPE_HAL, //Soft o hard
		hWnd, //Ventana
		D3DCREATE_HARDWARE_VERTEXPROCESSING, //Proceso de vertices por soft o hard
		&d3dpp, //Los parametros de buffers
		&Device); //El device que se crea

				  //Apago la luz para ver los colores y no todo oscuro
	Device->SetRenderState(D3DRS_LIGHTING, false);

	Input::Instance(hInstance, hWnd);
}

void Game::RenderFrame()
{
	Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 50, 100), 1.0f, 0);
	
	Device->BeginScene();

	if(_tileMap)
		_tileMap->Draw();
	for (int i = 0; i < _entities.size(); i++)
	{
		if (_entities[i])
			_entities[i]->Render();
	}

	Device->EndScene();
	Device->Present(NULL, NULL, NULL, NULL);
}

void Game::Run(HINSTANCE hInstance, int nCmdShow)
{
	InitD3D(hInstance, nCmdShow);
	Init();

	_lastFrameMs = Time();

	while (true)
	{
		_currentFrameMs = Time();
		_deltaTime = (_currentFrameMs - _lastFrameMs) / 1000.0f;
		_lastFrameMs = _currentFrameMs;
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

		Input::CheckInput();
		Update();
		RenderFrame();
	}
}


void Game::AddEntitie(MeshRenderer* e)
{
	_entities.push_back(e);
}

void Game::AddMaterial(Material * m)
{
	_materials.push_back(m);
}

void Game::AddModel(Model * model)
{
	_models.push_back(model);
}

int Game::Time()
{
	time_point<system_clock> actualTime = system_clock::now();
	system_clock::duration duration = actualTime.time_since_epoch();
	milliseconds ms = duration_cast<milliseconds>(duration);
	return ms.count();
}

float Game::DeltaTime()
{
	return abs(_deltaTime);
}

std::vector<MeshRenderer*> Game::GetMeshes()
{
	return _entities;
}

Camera * Game::GetCamera()
{
	return _camera;
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

