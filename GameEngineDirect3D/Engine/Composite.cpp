#include "stdafx.h"
#include "Composite.h"

Composite::Composite()
{
}

Composite::~Composite()
{
}

void Composite::Add(Component * component)
{
	components.push_back(component);
	component->SetParent(this);
}

void Composite::Remove(Component * component)
{
	//components.
}

void Composite::Update()
{
	UpdateComposite();

	for (size_t i = 0; i < components.size(); i++)
		components[i]->Update();
}

void Composite::Render()
{
	RenderComposite();

	for (size_t i = 0; i < components.size(); i++)
		components[i]->Render();
}


