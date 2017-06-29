#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}

Player::Player(LPDIRECT3DDEVICE9 dev)
{
	SetDevice(dev);
	std::vector<WORD> indexes = { 3, 0, 1, 3, 1, 2 };

	std::vector<Vertex> vertexes =
	{
		{ -0.5f, +0.5f, 0.0f, 0.0f, 0.0f },
		{ +0.5f, +0.5f, 0.0f, 2.0f, 0.0f },
		{ +0.5f, -0.5f, 0.0f, 2.0f, 2.0f },
		{ -0.5f, -0.5f, 0.0f, 0.0f, 2.0f },
	};
	Model* m = new Model(dev, vertexes, indexes, 2);
	LoadModel(m);

	Texture* tex1 = new Texture(dev);
	tex1->LoadTexture(L"../particle1.png");

	Material* mat = new Material(tex1, dev);
	SetMaterial(mat);

	ScaleMesh(D3DXVECTOR3(0.5, 0.5, 1));
	SetPosition(-0.5, 0, 1);

	//GetMaterial()->AddBlending();
	//GetMaterial()->AlphaBlending();
	GetMaterial()->MultiBlending();

}


Player::~Player()
{
}

void Player::Update()
{
	WaterEffect();
	if (Game::GetInput()->KeyPressed(ACTION::MOVE_RIGHT))
		MoveRight();
	if (Game::GetInput()->KeyJustPressed(ACTION::MOVE_LEFT))
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
}

std::string Player::GetType() const
{
	return "Player";
}