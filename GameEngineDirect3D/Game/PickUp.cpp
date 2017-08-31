#include "stdafx.h"
#include "PickUp.h"


PickUp::PickUp()
{
	_transform = GetComponent<Transform>();
	_transform->ScaleMesh(D3DXVECTOR3(0.5, 0.5, 1));
	_transform->SetPosition(0, 0.5, 1);
}


PickUp::~PickUp()
{
}

void PickUp::Init()
{
	_material = GetComponent<Material>();
	//_material->AddBlending();
}

void PickUp::UpdateComposite()
{
	Move();
}

void PickUp::Move()
{
	if (_transform->position.x <= 0.5 && _direction == 1)
		_transform->MoveRight(0.3* Game::DeltaTime());
	else _direction = -1;
	if (_transform->position.x >= -0.5 && _direction == -1)
		_transform->MoveLeft(0.3* Game::DeltaTime());
	else _direction = 1;
}

std::string PickUp::GetType() const
{
	return "PickUp";
}
