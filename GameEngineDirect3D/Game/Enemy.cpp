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

	Texture* tex1 = new Texture(dev);
	tex1->LoadTexture(L"../redCircle.jpg");

	Material* mat = new Material(m, tex1, dev);
	SetMaterial(mat);

	SetPosition(0, 0, 1);

	//GetMaterial()->AlphaBlending();
	GetMaterial()->MultiBlending();
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
