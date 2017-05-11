#pragma once
#include <d3d9.h>//Busca el header de directx en los path
#pragma comment (lib, "d3d9.lib") //Incluyo la lib a mi proyecto
#include "EngineApi.h"
#include "stdafx.h"

class ENGINE_API Game
{
public:
	Game();
	~Game();

	void Run(_In_     HINSTANCE hInstance,
		_In_     int       nCmdShow);
};

