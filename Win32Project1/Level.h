#pragma once
#include "Player.h"
#include "Enemy.h"
#include <list>

class Level
{
private:
	Player player;
    std::list<Enemy> enemys;
public:
	Level();
	~Level();
};

