#pragma once
#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

void Enemy::Update()
{

}

void Enemy::Move(D3DXVECTOR3 pos)
{
	Translate(pos);
}

void Enemy::Rotate(D3DXVECTOR3 rot)
{
	Rotate(rot);
}

void Enemy::Scale(D3DXVECTOR3 sca)
{
	Scale(sca);
}