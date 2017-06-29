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
	tex1->LoadTexture(L"../particle.png");

	Material* mat = new Material(tex1, dev);
	SetMaterial(mat);

	//ScaleMesh(D3DXVECTOR3(0.5, 0.5, 1));
	SetPosition(0.25, 0, 1);

	GetMaterial()->AlphaBlending();
	//GetMaterial()->MultiBlending();
}


Enemy::~Enemy()
{
}

void Enemy::Init()
{
}

void Enemy::Update()
{
	static float num = 0;
	RotateMesh(D3DXVECTOR3(0, 0, num));
	num += 0.01;
}

void Enemy::Move()
{
	
}

void Enemy::Escape(std::vector<Entity*> entities)
{
	for each (Entity* var in entities)
	{
		if(var->GetType() == "Player")
			if (abs((GetTransform().position - var->GetTransform().position).x) < 0.5)
				MoveForward();
	}
}

std::string Enemy::GetType() const
{
	return "Enemy";
}
