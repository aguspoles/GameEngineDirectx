#include "stdafx.h"
#include "Entity.h"


Entity::Entity()
{
	_m = nullptr;
	_dev = nullptr;
}

Entity::Entity(LPDIRECT3DDEVICE9 dev, Model *m)
{
	_dev = dev;
	_m = m;
}


Entity::~Entity() 
{

}

void Entity::Render()
{
	/*D3DXMATRIX parentModel = GetModelMatrix(
		D3DXVECTOR3(0.5f, 0, 0),
		D3DXVECTOR3(0, 0, 0.5),
		D3DXVECTOR3(0.5f, 0.5f, 0.5f));
	_dev->SetTransform(D3DTS_WORLD, &parentModel);*/
	//especificamos el formato del vertice
	_dev->SetFVF(CUSTOMFVF);
	//especificamos cual vb vamos a usar
	_dev->SetStreamSource(0, _m->GetVertexBuffer(), 0, sizeof(Vertex));
	//especificamos q indices vamos  a usar
	_dev->SetIndices(_m->GetIndexBuffer());
	//esto apga el culling de la placa para ver si
	//nuestro modelo...
	_dev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
    _dev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);
}

void Entity::LoadModel(Model *m)
{
	_m = m;
}

void Entity::SetDevice(LPDIRECT3DDEVICE9 dev)
{
	_dev = dev;
}

D3DXMATRIX Entity::GetModelMatrix(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 sca)
{
	D3DXMATRIX transMat;
	D3DXMatrixIdentity(&transMat);
	transMat._41 = pos.x;
	transMat._42 = pos.y;
	transMat._43 = pos.z;

	D3DXMATRIX scaMat;
	D3DXMatrixIdentity(&scaMat);
	scaMat._11 = sca.x;
	scaMat._22 = sca.y;
	scaMat._33 = sca.z;

	D3DXMATRIX rotZMat;
	D3DXMatrixIdentity(&rotZMat);
	rotZMat._11 = cos(rot.z);
	rotZMat._12 = sin(rot.z);
	rotZMat._21 = -sin(rot.z);
	rotZMat._22 = cos(rot.z);

	return scaMat * rotZMat * transMat;
};
