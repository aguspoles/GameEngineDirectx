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
	//especificamos el formato del vertice
	_dev->SetFVF(CUSTOMFVF);
	//especificamos cual vb vamos a usar
	_dev->SetStreamSource(0, _m->GetVertexBuffer(), 0, sizeof(Vertex));
	//especificamos q indices vamos  a usar
	_dev->SetIndices(_m->GetIndexBuffer());
	//esto apga el culling de la placa para ver si
	//nuestro modelo...
	//dev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	_dev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 4);
}

void Entity::LoadModel(Model & m)
{
	_m = &m;
}

void Entity::SetDevice(LPDIRECT3DDEVICE9 dev)
{
	_dev = dev;
}

