#include "stdafx.h"
#include "Entity.h"

Entity::Entity()
{
	_model = nullptr;
	_dev = nullptr;
	D3DXMatrixIdentity(&_rotateMatrix);
	D3DXMatrixIdentity(&_scaleMatrix);
	D3DXMatrixIdentity(&_translateMatrix);
	D3DXMatrixIdentity(&_modelMatrix);
}

Entity::Entity(LPDIRECT3DDEVICE9 dev, Model *m)
{
	_dev = dev;
	_model = m;
	D3DXMatrixIdentity(&_rotateMatrix);
	D3DXMatrixIdentity(&_scaleMatrix);
	D3DXMatrixIdentity(&_translateMatrix);
	D3DXMatrixIdentity(&_modelMatrix);
}


Entity::~Entity()
{

}

void Entity::Render(Camera* cam)
{
	_dev->SetTransform(D3DTS_WORLD, &_modelMatrix);
	if(cam)
		cam->SetRenderView(_dev);
	//especificamos el formato del vertice
	_dev->SetFVF(CUSTOMFVF);
	//especificamos cual vb vamos a usar
	_dev->SetStreamSource(0, _model->GetVertexBuffer(), 0, sizeof(Vertex));
	//especificamos q indices vamos  a usar
	_dev->SetIndices(_model->GetIndexBuffer());
	//esto apga el culling de la placa para ver si
	//nuestro modelo...
	//_dev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	_dev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0,
		(_model->GetVertexes()).size(), 0, _model->GetPrimitivesCount());
}

void Entity::LoadModel(Model *m)
{
	_model = m;
}

void Entity::SetDevice(LPDIRECT3DDEVICE9 dev)
{
	_dev = dev;
}

void Entity::ModelMatrix(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 sca)
{
	D3DXMATRIX rotX;
	D3DXMATRIX rotY;
	D3DXMATRIX rotZ;
	D3DXMatrixRotationZ(&rotZ, rot.z);
	D3DXMatrixRotationX(&rotX, rot.x);
	D3DXMatrixRotationY(&rotY, rot.y);
	D3DXMatrixScaling(&_scaleMatrix, sca.x, sca.y, sca.z);
	D3DXMatrixTranslation(&_translateMatrix, pos.x, pos.y, pos.z);
	_rotateMatrix = rotZ * rotX * rotY;
	/*D3DXMatrixIdentity(&_translateMatrix);
	_translateMatrix._41 = pos.x;
	_translateMatrix._42 = pos.y;
	_translateMatrix._43 = pos.z;
	D3DXMatrixIdentity(&_scaleMatrix);
	_scaleMatrix._11 = sca.x;
	_scaleMatrix._22 = sca.y;
	_scaleMatrix._33 = sca.z;
	D3DXMatrixIdentity(&_rotateMatrix);
	_rotateMatrix._11 = cos(rot.z);
	_rotateMatrix._12 = sin(rot.z);
	_rotateMatrix._21 = -sin(rot.z);
	_rotateMatrix._22 = cos(rot.z);*/
	_modelMatrix = _scaleMatrix * _rotateMatrix * _translateMatrix;
}

void Entity::SetModelMatrix(D3DXMATRIX model)
{
	_modelMatrix = model;
}

void Entity::SetChildModelMatrix(D3DXMATRIX parent)
{
	_modelMatrix *= parent;
}

D3DXMATRIX Entity::GetModelMatrix()
{
	return _modelMatrix;
}

void Entity::Translate(D3DXVECTOR3 pos)
{
	D3DXMatrixTranslation(&_translateMatrix, pos.x, pos.y, pos.z);
	/*D3DXMatrixIdentity(&_translateMatrix);
	_translateMatrix._41 = pos.x;
	_translateMatrix._42 = pos.y;
	_translateMatrix._43 = pos.z;*/
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
	/*D3DXMatrixIdentity(&_rotateMatrix);
	_rotateMatrix._11 = cos(rot.z);
	_rotateMatrix._12 = sin(rot.z);
	_rotateMatrix._21 = -sin(rot.z);
	_rotateMatrix._22 = cos(rot.z);*/
	_modelMatrix = _rotateMatrix * _scaleMatrix * _translateMatrix;
}

void Entity::Scale(D3DXVECTOR3 scal)
{
	D3DXMatrixScaling(&_scaleMatrix, scal.x, scal.y, scal.z);
	/*D3DXMatrixIdentity(&_scaleMatrix);
	_scaleMatrix._11 = scal.x;
	_scaleMatrix._22 = scal.y;
	_scaleMatrix._33 = scal.z;*/
	_modelMatrix = _rotateMatrix * _scaleMatrix * _translateMatrix;
}