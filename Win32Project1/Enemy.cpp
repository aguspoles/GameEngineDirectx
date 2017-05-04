#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

Enemy::Enemy(int x, int y)
{
	locationX = x;
	locationY = y;
}

void Enemy::Movement()
{
	if (locationX < 78 && flag)
		locationX++;
	else flag = false;
	if (locationX > 0 && !flag)
		locationX--;
	else flag = true;
}

int Enemy::GetLocationX()
{
	return locationX;
}

int Enemy::GetLocationY()
{
	return locationY;
}

void Enemy::SetLocationX(int x)
{
	locationX = x;
}

void Enemy::SetLocationY(int y)
{
	locationY = y;
}