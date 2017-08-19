#include "stdafx.h"
#include "PickUp.h"


PickUp::PickUp()
{
}

PickUp::PickUp(LPDIRECT3DDEVICE9 dev)
{
	SetDevice(dev);

	ScaleMesh(D3DXVECTOR3(0.5, 0.5, 1));
	SetPosition(0, 0.5, 1);
}


PickUp::~PickUp()
{
}

void PickUp::Init()
{
	//GetMaterial()->AddBlending();
}

void PickUp::Update()
{
	Move();
}

void PickUp::Move()
{
	if (GetTransform().position.x <= 0.5 && _direction == 1)
		MoveRight(0.3* Game::DeltaTime());
	else _direction = -1;
	if (GetTransform().position.x >= -0.5 && _direction == -1)
		MoveLeft(0.3* Game::DeltaTime());
	else _direction = 1;
}

std::string PickUp::GetType() const
{
	return "PickUp";
}
