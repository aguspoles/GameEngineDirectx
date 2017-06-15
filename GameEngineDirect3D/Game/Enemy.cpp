#pragma once
#include "stdafx.h"
#include "Enemy.h"


Enemy::Enemy()
{
}

Enemy::Enemy(LPDIRECT3DDEVICE9 dev)
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

	ModelMatrix(D3DXVECTOR3(0, 0, 1.0f),
		D3DXVECTOR3(0, 0, 0),
		D3DXVECTOR3(0.5f, 0.5f, 0.5f));
}


Enemy::~Enemy()
{
}

void Enemy::Init()
{
}

void Enemy::Update()
{

}

std::string Enemy::GetType() const
{
	return "Enemy";
}
