#pragma once

#include "resource.h"
#include "Game.h"

class GameApp : public Game
{
private:
public:
	GameApp();
	~GameApp();

	void Init_Graphics();
};