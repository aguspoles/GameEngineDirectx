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
	{
		_components[i]->Update();
	}
}

void Composite::Render()
{
	/*D3DXMATRIX originalModelMatrix = *_transform->GetModelMatrix();
	Composite* parent = GetParent();
	if (parent)
	{
		_parentTransform = parent->GetTransform();
		_transform->SetModelMatrix(*_parentTransform->GetModelMatrix() * originalModelMatrix);
	}*/
	/*Composite* parent = GetParent();
	D3DXMATRIX original = *_transform->GetModelMatrix();
	D3DXMATRIX modelMatrix = original;
	while (parent)
	{
		D3DXMATRIX parentMatrix = *(parent->GetComponent<Transform>()->GetModelMatrix());
		modelMatrix *= parentMatrix;
		parent = parent->GetParent();
	}

	_transform->SetModelMatrix(modelMatrix);*/
	//_transform->SetModelMatrix(original);
	RenderComposite();
	for (size_t i = 0; i < _components.size(); i++)
	{
	    _components[i]->Render();
	}
}

void Composite::Render(D3DXMATRIX modelMatrix)
{
	RenderComposite(modelMatrix);
	Composite* parent = GetParent();
	for (size_t i = 0; i < _components.size(); i++)
	{
		if (parent)
		{
		     modelMatrix *= *parent->GetTransform()->GetModelMatrix();
			_components[i]->Render(modelMatrix);
		}
		else _components[i]->Render();
	}
}

Transform * Composite::GetTransform()
{
	return _transform;
}


