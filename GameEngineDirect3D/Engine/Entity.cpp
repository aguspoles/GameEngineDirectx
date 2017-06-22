#include "stdafx.h"
#include "Entity.h"

Entity::Entity() : _model(NULL), _dev(NULL), _texture(NULL), _isVisible(true)
{
	D3DXMatrixIdentity(&_rotateMatrix);
	D3DXMatrixIdentity(&_scaleMatrix);
	D3DXMatrixIdentity(&_translateMatrix);
	D3DXMatrixIdentity(&_modelMatrix);
}

Entity::Entity(LPDIRECT3DDEVICE9 dev, Model* m) : _model(m), _dev(dev), _texture(NULL), _isVisible(true)
{
	D3DXMatrixIdentity(&_rotateMatrix);
	D3DXMatrixIdentity(&_scaleMatrix);
	D3DXMatrixIdentity(&_translateMatrix);
	D3DXMatrixIdentity(&_modelMatrix);
}


Entity::~Entity()
{
	if (_texture)
	{
		delete _texture;
		_texture = NULL;
	}
	if (_model)
	{
		delete _model;
		_model = NULL;
	}
}

void Entity::Render()
{
	_texture->Update();
	//especificamos el formato del vertice
	_dev->SetFVF(CUSTOMFVF);
	_dev->SetTransform(D3DTS_WORLD, &_modelMatrix);
	//especificamos cual vb vamos a usar
	_dev->SetStreamSource(0, _model->GetVertexBuffer(), 0, sizeof(Vertex));
	//especificamos q indices vamos  a usar
	_dev->SetIndices(_model->GetIndexBuffer());
	//esto apga el culling de la placa 
	//_dev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	_dev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0,
		(_model->GetVertexes()).size(), 0, _model->GetPrimitivesCount());
}

void Entity::LoadModel(Model* m)
{
	_model = m;
}

void Entity::SetDevice(LPDIRECT3DDEVICE9 dev)
{
	_dev = dev;
}

LPDIRECT3DDEVICE9 Entity::GetDevice()
{
	return _dev;
}

void Entity::SetTexture(Texture* tex)
{
	_texture = tex;
}

Texture * Entity::GetTexture()
{
	return _texture;
}

void Entity::ModelMatrix(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 sca)
{
	_transform.position = pos;
	_transform.rotation = rot;
	_transform.scale = sca;
	D3DXMATRIX rotX;
	D3DXMATRIX rotY;
	D3DXMATRIX rotZ;
	D3DXMatrixRotationZ(&rotZ, rot.z);
	D3DXMatrixRotationX(&rotX, rot.x);
	D3DXMatrixRotationY(&rotY, rot.y);
	D3DXMatrixScaling(&_scaleMatrix, sca.x, sca.y, sca.z);
	D3DXMatrixTranslation(&_translateMatrix, pos.x, pos.y, pos.z);
	_rotateMatrix = rotZ * rotX * rotY;
	_modelMatrix = _scaleMatrix * _rotateMatrix * _translateMatrix;
}

void Entity::SetModelMatrix(D3DXMATRIX model)
{
	_modelMatrix = model;
}

void Entity::SetParent(Entity* parent)
{
	_modelMatrix *= parent->GetModelMatrix();
}

D3DXMATRIX Entity::GetModelMatrix()
{
	return _modelMatrix;
}

void Entity::Translate(D3DXVECTOR3 pos)
{
	_transform.position = pos;
	D3DXMatrixTranslation(&_translateMatrix, _transform.position.x,
		                                     _transform.position.y,
		                                     _transform.position.z);
	_modelMatrix = _rotateMatrix * _scaleMatrix * _translateMatrix;
}

void Entity::Rotate(D3DXVECTOR3 rot)
{
	D3DXMATRIX rotX;
	D3DXMATRIX rotY;
	D3DXMATRIX rotZ;
	D3DXMatrixRotationZ(&rotZ, rot.z);
	D3DXMatrixRotationX(&rotX, rot.x);
	D3DXMatrixRotationY(&rotY, rot.y);
	_rotateMatrix = rotZ * rotX * rotY;
	_transform.rotation = rot;
	_modelMatrix = _rotateMatrix * _scaleMatrix * _translateMatrix;
}

void Entity::Scale(D3DXVECTOR3 scal)
{
	D3DXMatrixScaling(&_scaleMatrix, scal.x, scal.y, scal.z);
	_transform.scale = scal;
	_modelMatrix = _rotateMatrix * _scaleMatrix * _translateMatrix;
}

void Entity::MoveForward()
{
	float vel = 0.03;
	D3DXVECTOR3 worldForward(0, 0, 1);
	D3DXVECTOR4 objForward;
	D3DXVec3Transform(&objForward, &worldForward, &_rotateMatrix);
	D3DXVECTOR3 forward(objForward.x, objForward.y, objForward.z);
	_transform.position += forward * vel;
	Translate(_transform.position);
}

void Entity::MoveRight()
{
    float vel = 0.03;
	D3DXVECTOR3 worldRight(1, 0, 0);
	D3DXVECTOR4 objRight;
	D3DXVec3Transform(&objRight, &worldRight, &_rotateMatrix);
	D3DXVECTOR3 right(objRight.x, objRight.y, objRight.z);
	_transform.position += right * vel;
	Translate(_transform.position);
}

void Entity::MoveLeft()
{
	float vel = 0.03;
	D3DXVECTOR3 worldLeft(-1, 0, 0);
	D3DXVECTOR4 objLeft;
	D3DXVec3Transform(&objLeft, &worldLeft, &_rotateMatrix);
	D3DXVECTOR3 left(objLeft.x, objLeft.y, objLeft.z);
	_transform.position += left * vel;
	Translate(_transform.position);
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