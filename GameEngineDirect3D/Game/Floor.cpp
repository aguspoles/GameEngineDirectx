#include "stdafx.h"
#include "Floor.h"


Floor::Floor()
{
}

Floor::Floor(LPDIRECT3DDEVICE9 dev)
{
	SetDevice(dev);
	//SetPosition(0, 0, 9);
}


Floor::~Floor()
{
}

void Floor::Init()
{
}

void Floor::Update()
{
}

std::string Floor::GetType() const
{
	return "tile";
}
