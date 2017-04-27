#include "stdafx.h"
#include "Entity.h"


Entity::Entity(LPDIRECT3DDEVICE9 dev) {
	_dev = dev;
	Vertex vertexes[] =
	{
		//rectangulo superior
		{ 100.0f, 0.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(50,50,0) },
		{ 540.0f, 0.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(0,100,0) },
		{ 100.0f, 100.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(50,0,100) },
		{ 540.0f, 100.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(0,0,255) },
		//rectangulo inferior
		{ 270.0f, 100.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(255,0,0) },
		{ 370.0f, 100.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(0,255,0) },
		{ 270.0f, 480.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(255,255,0) },
		{ 370.0f, 480.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(0,0,255) },
	};

	WORD indexes[] =
	{
		0,3,2,0,1,3, 4,5,6,6,5,7
	};

	_dev->CreateVertexBuffer(8 * sizeof(Vertex),
		D3DUSAGE_WRITEONLY,//el uso q le vamos a dar
		CUSTOMFVF,
		D3DPOOL_MANAGED,//lo subimos a vram
		&vb,
		NULL);


	_dev->CreateIndexBuffer(
		12 * sizeof(WORD),
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&ib,
		NULL
	);

	//puntero a la memoria del vb en la vram
	VOID *data;
	//compiamos el array de veritces q esta en la ram de la cpu 
	//a el puntero del vb en la vram, especificando cuantos 
	//bytes vamos a copiar
	vb->Lock(0, 0, &data, 0);
	memcpy(data, vertexes, 8 * sizeof(Vertex));
	vb->Unlock();

	ib->Lock(0, 0, &data, 0);
	memcpy(data, indexes, 12 * sizeof(WORD));
	ib->Unlock();
}


Entity::~Entity(){

}

void Entity::Render() {
	//especificamos el formato del vertice
	_dev->SetFVF(CUSTOMFVF);
	//especificamos cual vb vamos a usar
	_dev->SetStreamSource(0, vb, 0, sizeof(Vertex));
	//especificamos q indices vamos  a usar
	_dev->SetIndices(ib);
	//esto apga el culling de la placa para ver si
	//nuestro modelo...
	//dev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	_dev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 4);
}

void Entity::LoadModel(Model &m)
{
}

void Entity::Clean() {
	vb->Release();
	ib->Release();
}
