#include "stdafx.h"
#include "PickUp.h"


PickUp::PickUp()
{
}

PickUp::PickUp(LPDIRECT3DDEVICE9 dev)
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
	tex1->LoadTexture(L"../metal.jpg");

	Material* mat = new Material(tex1, dev);
	SetMaterial(mat);

	ScaleMesh(D3DXVECTOR3(0.5, 0.5, 1));
	SetPosition(0, 0.5, 1);

	GetMaterial()->AddBlending();
}


PickUp::~PickUp()
{
}

void PickUp::Init()
{
}

void PickUp::Update()
{
	Move();
}

void PickUp::Move()
{
	if (GetTransform().position.x <= 0.5 && _direction == 1)
		MoveRight();
	else _direction = -1;
	if (GetTransform().position.x >= -0.5 && _direction == -1)
		MoveLeft();
	else _direction = 1;
}

std::string PickUp::GetType() const
{
	return "PickUp";
}
