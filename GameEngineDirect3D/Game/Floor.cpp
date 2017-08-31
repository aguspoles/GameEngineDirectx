#include "stdafx.h"
#include "Floor.h"


Floor::Floor()
{
	_transform = GetComponent<Transform>();
}


Floor::~Floor()
{
}

void Floor::Init()
{
	_material = GetComponent<Material>();
}

void Floor::UpdateComposite()
{
}

std::string Floor::GetType() const
{
	return "tile";
}
