#include "stdafx.h"
#include "Composite.h"

Composite::Composite()
{
	_transform = new Transform();
	Add(_transform);
}

Composite::~Composite()
{
	if (_transform)
		delete _transform;
}

void Composite::Add(Component * component)
{
	_components.push_back(component);
	component->SetParent(this);
}

void Composite::Remove(Component * component)
{
	//components.
}

void Composite::Update()
{
	UpdateComposite();

	for (size_t i = 0; i < _components.size(); i++)
		_components[i]->Update();
}

void Composite::Render()
{
	Composite* parent = GetParent();
	D3DXMATRIX original = *_transform->GetModelMatrix();
	D3DXMATRIX modelMatrix = original;
	while (parent)
	{
		D3DXMATRIX parentMatrix = *(parent->GetComponent<Transform>()->GetModelMatrix());
		modelMatrix *= parentMatrix;
		parent = parent->GetParent();
	}

	_transform->SetModelMatrix(modelMatrix);
	RenderComposite();
	_transform->SetModelMatrix(original);
	for (size_t i = 0; i < _components.size(); i++)
		_components[i]->Render();
}

Transform * Composite::GetTransform()
{
	return _transform;
}


