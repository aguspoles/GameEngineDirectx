#pragma once
#include "Enemy.h"

class Player
{
private:
	int locationX;
	int locationY;
	bool UP, DOWN, LEFT, RIGHT;
public:
	Player();
	~Player();



 Player(int x, int y);

 void Movement();
 void EnemyCollision(Enemy e);

 int GetLocationX();


 int GetLocationY();


 void SetLocationX(int x);


 void SetLocationY(int y);

};

