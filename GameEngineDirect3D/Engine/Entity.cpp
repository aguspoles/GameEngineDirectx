#include "stdafx.h"
#include "Entity.h"

Entity::Entity() : _dev(NULL), _isVisible(true), _material(NULL)
{
	_transform.position = D3DXVECTOR3(0, 0, 1);
}

Entity::Entity(LPDIRECT3DDEVICE9 dev) : _dev(dev), _isVisible(true), _material(NULL)
{
	_transform.position = D3DXVECTOR3(0, 0, 1);
}


Entity::~Entity()
{
	if(_material)
		delete _material;
}

void Entity::Render()
{
	D3DXMATRIX* tex = _material->GetTextureMatrix();
	_material->GetTexture()->SetTexture(tex);
	_material->SetBlend();
	//especificamos el formato del vertice
	_dev->SetFVF(CUSTOMFVF);
	_dev->SetTransform(D3DTS_WORLD, _material->GetModelMatrix());
	//especificamos cual vb vamos a usar
	_dev->SetStreamSource(0, _material->GetModel()->GetVertexBuffer(), 0, sizeof(Vertex));
	//especificamos q indices vamos  a usar
	_dev->SetIndices(_material->GetModel()->GetIndexBuffer());
	//esto apga el culling de la placa 
	//_dev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	_dev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0,
		(_material->GetModel()->GetVertexes()).size(), 0, _material->GetModel()->GetPrimitivesCount());
}

Material * Entity::GetMaterial()
{
	return _material;
}

void Entity::SetMaterial(Material * m)
{
	_material = m;
}

void Entity::SetDevice(LPDIRECT3DDEVICE9 dev)
{
	_dev = dev;
}

LPDIRECT3DDEVICE9 Entity::GetDevice()
{
	return _dev;
}

void Entity::SetChildModel(Entity* child)
{
	*(_material->GetModelMatrix()) *= *(child->GetMaterial()->GetModelMatrix());
}

void Entity::SetPosition(float x, float y, float z)
{
	_transform.position = D3DXVECTOR3(x, y, z);
	_material->TranslateMesh(_transform.position);
}

void Entity::MoveForward()
{
	float vel = 0.03;
	D3DXVECTOR3 worldForward(0, 0, 1);
	D3DXVECTOR4 objForward;
	D3DXVec3Transform(&objForward, &worldForward, _material->GetRotateMeshMatrix());
	D3DXVECTOR3 forward(objForward.x, objForward.y, objForward.z);
	_transform.position += forward * vel;
	_material->TranslateMesh(_transform.position);
}

void Entity::MoveRight()
{
    float vel = 0.03;
	D3DXVECTOR3 worldRight(1, 0, 0);
	D3DXVECTOR4 objRight;
	D3DXVec3Transform(&objRight, &worldRight, _material->GetRotateMeshMatrix());
	D3DXVECTOR3 right(objRight.x, objRight.y, objRight.z);
	_transform.position += right * vel;
	_material->TranslateMesh(_transform.position);
}

void Entity::MoveLeft()
{
	float vel = 0.03;
	D3DXVECTOR3 worldLeft(-1, 0, 0);
	D3DXVECTOR4 objLeft;
	D3DXVec3Transform(&objLeft, &worldLeft, _material->GetRotateMeshMatrix());
	D3DXVECTOR3 left(objLeft.x, objLeft.y, objLeft.z);
	_transform.position += left * vel;
	_material->TranslateMesh(_transform.position);
}

float Entity::GetForward()
{
	return _transform.position.z;
}

float Entity::GetUp()
{
	return _transform.position.y;
}

float Entity::GetRight()
{
	return _transform.position.x;
}

bool Entity::IsVisible() const
{
	return _isVisible;
}

Transform Entity::GetTransform()
{
	return _transform;
}

