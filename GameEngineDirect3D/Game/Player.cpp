#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}

Player::Player(LPDIRECT3DDEVICE9 dev)
{
	SetDevice(dev);

	//ScaleMesh(D3DXVECTOR3(0.5, 0.5, 1));
	SetPosition(0, 0, 8);
	RotateMesh(D3DXVECTOR3(0,0,D3DXToRadian(180)));
	//RotateMesh(D3DXVECTOR3(0, 0, D3DXToRadian(0)));

}


Player::~Player()
{
}

void Player::Update()
{
	//WaterEffect();
	//MoveBackWard();
	GetCurrentAnimation()->Play();
	if (Input::KeyPressed("MOVE_RIGHT"))
	{
		MoveRight();
	}
	if (Input::KeyJustPressed("MOVE_LEFT"))
		MoveLeft();
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