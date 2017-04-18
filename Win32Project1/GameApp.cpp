#pragma once
#include "stdafx.h"
#include "GameApp.h"
#include "Game.h"


int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	Game* g = new Game();
	g->Run(hInstance, hPrevInstance, lpCmdLine, nCmdShow);

	return 0;
}