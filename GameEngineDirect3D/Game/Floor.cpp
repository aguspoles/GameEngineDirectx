#include "stdafx.h"
#include "Floor.h"


Floor::Floor()
{
}


Floor::~Floor()
{
}

void Floor::Init()
{
	_transform = GetComponent<Transform>();
	_material = GetComponent<Material>();
}

void Floor::UpdateComposite()
{
}

std::string Floor::GetType() const
{
	return "tile";
}
