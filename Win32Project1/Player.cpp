#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
}

Player::Player(int x, int y)
{
	locationX = x;
	locationY = y;
	UP = DOWN = LEFT = RIGHT = true;
}

void Player::Movement()
{

}

void Player::EnemyCollision(Enemy e)
{
	if (locationX == e.GetLocationX()
		&& locationY == e.GetLocationY())
	{
		
	}
}

int Player::GetLocationX()
{
	return locationX;
}

int Player::GetLocationY()
{
	return locationY;
}

void Player::SetLocationX(int x)
{
	locationX = x;
}

void Player::SetLocationY(int y)
{
	locationY = y;
}