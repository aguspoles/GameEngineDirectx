#include "stdafx.h"
#include "Component.h"


Component::Component()
{

}


Component::~Component()
{

}

void Component::Update()
{
}

void Component::Render()
{
}

void Component::Move(float offsetX, float offsetY)
{
	x += offsetX;
	y += offsetY;
}

void Component::SetParent(Composite * parent)
{
	this->parent = parent;
}

Composite * Component::GetParent()
{
	return parent;
}


