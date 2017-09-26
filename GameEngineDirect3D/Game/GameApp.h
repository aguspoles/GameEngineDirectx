#ifndef GAMEAPP_H
#define GAMEAPP_H
#include "resource.h"
#include "Game.h"
#include "Camera.h"
#include "Player.h"
#include "PickUp.h"
#include "Floor.h"
//#include "TileMap.h"

class GameApp : public Game
{
private:
	//TileMap* _tileMap;
public:
	GameApp();
	~GameApp();

	void Update();
	void Init();
	void SetCamera();
};

#endif