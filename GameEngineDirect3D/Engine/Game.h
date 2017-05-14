#pragma once
#include "stdafx.h"
#include "EngineApi.h"

class ENGINE_API Game
{
public:
	Game();
	~Game();

	void Run(_In_     HINSTANCE hInstance,
		_In_     int       nCmdShow);
};

