#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}

Player::Player(LPDIRECT3DDEVICE9 dev)
{
	SetDevice(dev);

	//ScaleMesh(D3DXVECTOR3(0.5, 0.5, 1));
	SetPosition(0, 0, 9);
	RotateMesh(D3DXVECTOR3(0,0,D3DXToRadian(180)));
}


Player::~Player()
{
}

void Player::Update()
{
	//WaterEffect();
	//MoveBackWard();
	if (Input::KeyPressed("MOVE_RIGHT"))
	{
	    GetCurrentAnimation()->Play();
		MoveRight(0.3 * Game::DeltaTime());
	}
	if (Input::KeyPressed("MOVE_LEFT"))
	{ 
		GetCurrentAnimation()->Play();
		MoveLeft(0.3 * Game::DeltaTime());
	}
}

void Player::EnemyCollision(const std::vector<Entity*> &entities)
{

}

void Player::WaterEffect()
{
	static float num = 0;
	GetMaterial()->RotateTexture(D3DXVECTOR3(0, 0, num));
    GetMaterial()->Offset(D3DXVECTOR2(num, num));
	num += 0.01;
}

void Player::Init()
{
	//GetMaterial()->AddBlending();
	GetMaterial()->AlphaBlending();
	//GetMaterial()->MultiBlending();
}

std::string Player::GetType() const
{
	return "Player";
}