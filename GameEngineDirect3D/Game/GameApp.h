#ifndef GAMEAPP_H
#define GAMEAPP_H
#include "resource.h"
#include "Game.h"
#include "Player.h"
#include "PickUp.h"

class GameApp : public Game
{
private:
public:
	GameApp();
	~GameApp();

	void Run(_In_ HINSTANCE hInstance, _In_ int nCmdShow);
	void Update();
	void Init();
};

#endif