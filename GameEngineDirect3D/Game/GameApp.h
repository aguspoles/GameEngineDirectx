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

	void Update();
	void Init();
};

#endif