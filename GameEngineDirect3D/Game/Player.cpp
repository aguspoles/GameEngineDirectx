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
		_transform->MoveRight(1 * Game::DeltaTime());
	}
	if (Input::KeyPressed("MOVE_LEFT"))
	{ 
		GetCurrentAnimation()->Play();
		_transform->MoveLeft(1 * Game::DeltaTime());
	}

	D3DXMATRIX mvp = *_transform->GetModelMatrix() * game->GetCamera()->GetViewMatrix() * game->GetCamera()->GetProjectMatrix();
	_material->GetShadderEffect()->SetMatrix("mvp", &mvp);
	_material->GetShadderEffect()->SetVector("_Color", &D3DXVECTOR4(1, 0.5f, 0.5f, 0));
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