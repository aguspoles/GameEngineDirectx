#include "stdafx.h"
#include "Entity.h"

Entity::Entity() : _dev(NULL), _isVisible(true), _material(NULL), _model(NULL)
{
	D3DXMatrixIdentity(&_modelMatrix);
	D3DXMatrixIdentity(&_scaleMeshMatrix);
	D3DXMatrixIdentity(&_rotateMeshMatrix);
	D3DXMatrixIdentity(&_translateMeshMatrix);
	_transform.position = D3DXVECTOR3(0, 0, 1);
}

Entity::Entity(LPDIRECT3DDEVICE9 dev) : _dev(dev), _isVisible(true), _material(NULL), _model(NULL)
{
	D3DXMatrixIdentity(&_modelMatrix);
	D3DXMatrixIdentity(&_scaleMeshMatrix);
	D3DXMatrixIdentity(&_rotateMeshMatrix);
	D3DXMatrixIdentity(&_translateMeshMatrix);
	_transform.position = D3DXVECTOR3(0, 0, 1);
}


Entity::~Entity()
{
	
}

void Entity::Render()
{
	if (_material)
	{
		D3DXMATRIX* texMat = _material->GetTextureMatrix();
		_material->GetTexture()->SetTexture(texMat);
		_material->SetBlend();
	}
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
	//lo apago para que lo proximo que se dibuje no tenga blend necesariamente
	_dev->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
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

Model * Entity::GetModel()
{
	return _model;
}

void Entity::LoadModel(Model * m)
{
	_model = m;
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
	D3DXMatrixScaling(&_scaleMeshMatrix, sca.x, sca.y, sca.z);
	D3DXMatrixTranslation(&_translateMeshMatrix, pos.x, pos.y, pos.z);
	_rotateMeshMatrix = rotZ * rotX * rotY;
	_modelMatrix = _scaleMeshMatrix * _rotateMeshMatrix * _translateMeshMatrix;
}

D3DXMATRIX * Entity::GetModelMatrix()
{
	return &_modelMatrix;
}

D3DXMATRIX * Entity::GetTranslateMeshMatrix()
{
	return &_translateMeshMatrix;
}

D3DXMATRIX * Entity::GetRotateMeshMatrix()
{
	return &_rotateMeshMatrix;
}

D3DXMATRIX * Entity::GetScaleMeshMatrix()
{
	return &_scaleMeshMatrix;
}

void Entity::SetModelMatrix(D3DXMATRIX model)
{
	_modelMatrix = model;
}

void Entity::TranslateMesh(D3DXVECTOR3 pos)
{
	_transform.position = pos;
	D3DXMatrixTranslation(&_translateMeshMatrix, pos.x,
		pos.y,
		pos.z);
	_modelMatrix = _rotateMeshMatrix * _scaleMeshMatrix * _translateMeshMatrix;
}

void Entity::RotateMesh(D3DXVECTOR3 rot)
{
	_transform.rotation = rot;
	D3DXMATRIX rotX;
	D3DXMATRIX rotY;
	D3DXMATRIX rotZ;
	D3DXMatrixRotationZ(&rotZ, rot.z);
	D3DXMatrixRotationX(&rotX, rot.x);
	D3DXMatrixRotationY(&rotY, rot.y);
	_rotateMeshMatrix = rotZ * rotX * rotY;
	_modelMatrix = _rotateMeshMatrix * _scaleMeshMatrix * _translateMeshMatrix;
}

void Entity::ScaleMesh(D3DXVECTOR3 scal)
{
	_transform.scale = scal;
	D3DXMatrixScaling(&_scaleMeshMatrix, scal.x, scal.y, scal.z);
	_modelMatrix = _rotateMeshMatrix * _scaleMeshMatrix * _translateMeshMatrix;
}

void Entity::SetChildModel(Entity* child)
{
	_modelMatrix *= *(child->GetModelMatrix());
}

void Entity::SetPosition(float x, float y, float z)
{
	_transform.position = D3DXVECTOR3(x, y, z);
	TranslateMesh(_transform.position);
}

void Entity::MoveForward()
{
	float vel = 0.03;
	D3DXVECTOR3 worldForward(0, 0, 1);
	D3DXVECTOR4 objForward;
	D3DXVec3Transform(&objForward, &worldForward, &_rotateMeshMatrix);
	D3DXVECTOR3 forward(objForward.x, objForward.y, objForward.z);
	_transform.position += forward * vel;
	TranslateMesh(_transform.position);
}

void Entity::MoveRight()
{
    float vel = 0.03;
	D3DXVECTOR3 worldRight(1, 0, 0);
	D3DXVECTOR4 objRight;
	D3DXVec3Transform(&objRight, &worldRight, &_rotateMeshMatrix);
	D3DXVECTOR3 right(objRight.x, objRight.y, objRight.z);
	_transform.position += right * vel;
	TranslateMesh(_transform.position);
}

void Entity::MoveLeft()
{
	float vel = 0.03;
	D3DXVECTOR3 worldLeft(-1, 0, 0);
	D3DXVECTOR4 objLeft;
	D3DXVec3Transform(&objLeft, &worldLeft, &_rotateMeshMatrix);
	D3DXVECTOR3 left(objLeft.x, objLeft.y, objLeft.z);
	_transform.position += left * vel;
	TranslateMesh(_transform.position);
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

