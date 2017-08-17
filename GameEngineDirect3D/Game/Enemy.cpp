#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
}

Enemy::Enemy(LPDIRECT3DDEVICE9 dev)
{
	SetDevice(dev);

	//ScaleMesh(D3DXVECTOR3(0.5, 0.5, 1));
	SetPosition(0.25, 0, 0);
}


Enemy::~Enemy()
{
}

void Enemy::Init()
{
	GetMaterial()->AlphaBlending();
	//GetMaterial()->MultiBlending();
}

void Enemy::Update()
{
	static float num = 0;
	RotateMesh(D3DXVECTOR3(0, 0, num));
	num += 0.01;
}

void Enemy::Move()
{
	
}

void Enemy::Escape(std::vector<Entity*> entities)
{
	for each (Entity* var in entities)
	{
		if(var->GetType() == "Player")
			if (abs((GetTransform().position - var->GetTransform().position).x) < 0.5)
				MoveForward();
	}
}

std::string Enemy::GetType() const
{
	return "Enemy";
}
