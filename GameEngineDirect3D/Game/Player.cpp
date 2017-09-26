#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	_transform = GetComponent<Transform>(); 
	_transform->SetPosition(0, 0, 8);
}


Player::~Player()
{
}

void Player::UpdateComposite()
{
	//WaterEffect();
	//MoveBackWard();
	if (Input::KeyPressed("MOVE_RIGHT"))
	{
	    GetCurrentAnimation()->Play();
		_transform->MoveRight(5 * Game::DeltaTime());
		//_transform->RotateMesh(D3DXVECTOR3(0, 0, 1));
	}
	if (Input::KeyPressed("MOVE_LEFT"))
	{ 
		GetCurrentAnimation()->Play();
		_transform->MoveLeft(1 * Game::DeltaTime());
	}
}

void Player::EnemyCollision(const std::vector<MeshRenderer*> &entities)
{

}

void Player::WaterEffect()
{
	if (_material)
	{
		static float num = 0;
		_material->RotateTexture(D3DXVECTOR3(0, 0, num));
		_material->Offset(D3DXVECTOR2(num, num));
		num += 0.01;
	}
}

void Player::Init()
{
	_material = GetComponent<Material>();
	if (_material)
	{
		//GetMaterial()->AddBlending();
		//_material->AlphaBlending();
		//GetMaterial()->MultiBlending();
	}
}

std::string Player::GetType() const
{
	return "Player";
}