#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
	_transform = GetComponent<Transform>();
	//ScaleMesh(D3DXVECTOR3(0.5, 0.5, 1));
	_transform->SetPosition(-4, 0, 8);
}


Enemy::~Enemy()
{
}

void Enemy::Init()
{
	_material = GetComponent<Material>();
	_material->AlphaBlending();
}

void Enemy::UpdateComposite()
{
	static float num = 0;
	//_transform->RotateMesh(D3DXVECTOR3(0, 0, num));
	num += 0.01;
	//_transform->MoveForward(1);
}

void Enemy::Move()
{
	
}

void Enemy::Escape(std::vector<MeshRenderer*> entities)
{
	for each (MeshRenderer* var in entities)
	{
		auto other = var->GetComponent<Transform>();
		if(var->GetType() == "Player")
			if (abs((_transform->position - other->position).x) < 0.5)
				_transform->MoveForward(0.3* Game::DeltaTime());
	}
}

std::string Enemy::GetType() const
{
	return "Enemy";
}
