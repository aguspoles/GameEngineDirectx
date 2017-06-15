#pragma once
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
	tex1->LoadTexture(L"../huevo.jpg");
	SetTexture(tex1);

	ModelMatrix(D3DXVECTOR3(0, 0, 1.0f),
		D3DXVECTOR3(0, 0, 0),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f));
}


Player::~Player()
{
}

void Player::Update()
{
	if (Game::GetInput()->KeyPressed("Move Right"))
		MoveRight();
	if (Game::GetInput()->KeyJustPressed("Move Left"))
		MoveLeft();
}

void Player::EnemyCollision(const std::vector<Entity*> &entities)
{

}

void Player::Init()
{
}

std::string Player::GetType() const
{
	return "Player";
}