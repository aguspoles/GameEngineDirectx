#include "stdafx.h"
#include "Transform.h"


Transform::Transform()
{
	D3DXMatrixIdentity(&_modelMatrix);
	D3DXMatrixIdentity(&_scaleMeshMatrix);
	D3DXMatrixIdentity(&_rotateMeshMatrix);
	D3DXMatrixIdentity(&_translateMeshMatrix);
}


Transform::~Transform()
{
}

void Transform::ModelMatrix(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 sca)
{
	position = pos;
	rotation = rot;
	scale = sca;
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

D3DXMATRIX * Transform::GetModelMatrix()
{
	return &_modelMatrix;
}

D3DXMATRIX * Transform::GetTranslateMeshMatrix()
{
	return &_translateMeshMatrix;
}

D3DXMATRIX * Transform::GetRotateMeshMatrix()
{
	return &_rotateMeshMatrix;
}

D3DXMATRIX * Transform::GetScaleMeshMatrix()
{
	return &_scaleMeshMatrix;
}

void Transform::SetModelMatrix(D3DXMATRIX model)
{
	_modelMatrix = model;
}

void Transform::TranslateMesh(D3DXVECTOR3 pos)
{
	position = pos;
	D3DXMatrixTranslation(&_translateMeshMatrix, pos.x,
		pos.y,
		pos.z);
	_modelMatrix = _rotateMeshMatrix * _scaleMeshMatrix * _translateMeshMatrix;
}

void Transform::RotateMesh(D3DXVECTOR3 rot)
{
	rotation = rot;
	D3DXMATRIX rotX;
	D3DXMATRIX rotY;
	D3DXMATRIX rotZ;
	D3DXMatrixRotationZ(&rotZ, rot.z);
	D3DXMatrixRotationX(&rotX, rot.x);
	D3DXMatrixRotationY(&rotY, rot.y);
	_rotateMeshMatrix = rotZ * rotX * rotY;
	_modelMatrix = _rotateMeshMatrix * _scaleMeshMatrix * _translateMeshMatrix;
}

void Transform::ScaleMesh(D3DXVECTOR3 scal)
{
	scale = scal;
	D3DXMatrixScaling(&_scaleMeshMatrix, scal.x, scal.y, scal.z);
	_modelMatrix = _rotateMeshMatrix * _scaleMeshMatrix * _translateMeshMatrix;
}

void Transform::SetChildModel(Transform* child)
{
	_modelMatrix *= *(child->GetModelMatrix());
}

void Transform::SetPosition(float x, float y, float z)
{
	position = D3DXVECTOR3(x, y, z);
	TranslateMesh(position);
}

void Transform::MoveForward(float vel)
{
	D3DXVECTOR3 worldForward(0, 0, 1);
	D3DXVECTOR4 objForward;
	D3DXVec3Transform(&objForward, &worldForward, &_rotateMeshMatrix);
	D3DXVECTOR3 forward(objForward.x, objForward.y, objForward.z);
	position += forward * vel;
	TranslateMesh(position);
}

void Transform::MoveRight(float vel)
{
	D3DXVECTOR3 worldRight(1, 0, 0);
	D3DXVECTOR4 objRight;
	D3DXVec3Transform(&objRight, &worldRight, &_rotateMeshMatrix);
	D3DXVECTOR3 right(objRight.x, objRight.y, objRight.z);
    position += right * vel;
	TranslateMesh(position);
}

void Transform::MoveLeft(float vel)
{
	D3DXVECTOR3 worldLeft(-1, 0, 0);
	D3DXVECTOR4 objLeft;
	D3DXVec3Transform(&objLeft, &worldLeft, &_rotateMeshMatrix);
	D3DXVECTOR3 left(objLeft.x, objLeft.y, objLeft.z);
	position += left * vel;
	TranslateMesh(position);
}

void Transform::MoveBackWard(float vel)
{
	D3DXVECTOR3 worldBackWard(0, 0, -1);
	D3DXVECTOR4 objBackWard;
	D3DXVec3Transform(&objBackWard, &worldBackWard, &_rotateMeshMatrix);
	D3DXVECTOR3 backWard(objBackWard.x, objBackWard.y, objBackWard.z);
	position += backWard * vel;
	TranslateMesh(position);
}

float Transform::GetForward()
{
	return position.z;
}

float Transform::GetUp()
{
	return position.y;
}

float Transform::GetRight()
{
	return position.x;
}
