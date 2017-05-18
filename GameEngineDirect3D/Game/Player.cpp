#pragma once
#include "stdafx.h"
#include "Player.h"


Player::Player() 
{
	
}


Player::~Player()
{
}

void Player::Update()
{
	Move(D3DXVECTOR3(0,0,0));
}

void Player::Move(D3DXVECTOR3 pos)
{
	Translate(pos);
}

void Player::Rotate(D3DXVECTOR3 rot)
{
	Rotate(rot);
}

void Player::Scale(D3DXVECTOR3 sca)
{
	Scale(sca);
}

void Player::EnemyCollision(Enemy e)
{
	/*if (_transform.position == e.GetTransform().position)
		return;*/
}
