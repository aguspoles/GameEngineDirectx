#include "stdafx.h"
#include "Model.h"



Model::Model()
{
	_vb = nullptr;
	_ib = nullptr;
}

Model::Model(LPDIRECT3DDEVICE9 dev, Vertex vertexes[], WORD indexes[],
	int vertexesSize, int indexesSize)
{

	dev->CreateVertexBuffer(vertexesSize * sizeof(Vertex),
		D3DUSAGE_WRITEONLY,//el uso q le vamos a dar
		CUSTOMFVF,
		D3DPOOL_MANAGED,//lo subimos a vram
		&_vb,
		NULL);
	//puntero a la memoria del vb en la vram
	VOID *data;
	//compiamos el array de veritces q esta en la ram de la cpu 
	//a el puntero del vb en la vram, especificando cuantos 
	//bytes vamos a copiar
	_vb->Lock(0, 0, &data, 0);
	memcpy(data, vertexes, vertexesSize * sizeof(Vertex));
	_vb->Unlock();

	if (indexes)
	{
		dev->CreateIndexBuffer(
			indexesSize * sizeof(WORD),
			D3DUSAGE_WRITEONLY,
			D3DFMT_INDEX16,
			D3DPOOL_MANAGED,
			&_ib,
			NULL
		);
		VOID *indexData;
		_ib->Lock(0, 0, &indexData, 0);
		memcpy(indexData, indexes, indexesSize * sizeof(WORD));
		_ib->Unlock();
	}


}

LPDIRECT3DVERTEXBUFFER9 Model::GetVertexBuffer()
{
	return _vb;
}

LPDIRECT3DINDEXBUFFER9 Model::GetIndexBuffer()
{
	return _ib;
}


Model::~Model()
{
	_vb->Release();
	_ib->Release();
}
