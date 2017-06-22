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
	tex1->LoadTexture(L"../water1.jpg");
	SetTexture(tex1);
	GetTexture()->Offset(D3DXVECTOR2(0,0));
	GetTexture()->Tiling(D3DTADDRESS_WRAP, D3DTADDRESS_WRAP);

	ModelMatrix(D3DXVECTOR3(0, 0, 1.0f),
		D3DXVECTOR3(0, 0, 0),
		D3DXVECTOR3(1.0f, 1.0f, 1.0f));
}


Player::~Player()
{
}

void Player::Update()
{
	GetTexture()->WaterEffect();
	if (Game::GetInput()->KeyPressed(ACTION::MOVE_RIGHT))
		MoveRight();
	if (Game::GetInput()->KeyJustPressed(ACTION::MOVE_LEFT))
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