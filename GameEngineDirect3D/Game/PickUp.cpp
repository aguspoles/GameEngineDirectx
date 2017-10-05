#include "stdafx.h"
#include "PickUp.h"


PickUp::PickUp()
{

}


PickUp::~PickUp()
{
}

void PickUp::Init()
{
	_transform = GetComponent<Transform>();
	_transform->ScaleMesh(D3DXVECTOR3(0.5, 0.5, 1));
	_transform->SetPosition(-0.5, 0.5, 5);
	_material = GetComponent<Material>();
	//_material->AlphaBlending();
}

void PickUp::UpdateComposite()
{
	//Move();
	/*if (Input::KeyPressed("MOVE_LEFT"))
	{
		_transform->MoveLeft(1 * Game::DeltaTime());
	}*/
}

void PickUp::Move()
{
	if (_transform->position.x <= 0.5 && _direction == 1)
		_transform->MoveRight(0.5 * Game::DeltaTime());
	else _direction = -1;
	if (_transform->position.x >= -0.5 && _direction == -1)
		_transform->MoveLeft(0.5 * Game::DeltaTime());
	else _direction = 1;
}

std::string PickUp::GetType() const
{
	return "PickUp";
}
