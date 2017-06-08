#include "stdafx.h"
#include "GameApp.h"

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	Game* g = new GameApp();
	g->Run(hInstance, nCmdShow);

	delete g;
	return 0;
}