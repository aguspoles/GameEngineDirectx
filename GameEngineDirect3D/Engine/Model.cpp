#include "stdafx.h"
#include "Model.h"

Model::Model()
{
	_vb = nullptr;
	_ib = nullptr;
	_primitivesCount = 0;
}

Model::~Model()
{
	_vb->Release();
	_ib->Release();
}

Model::Model(LPDIRECT3DDEVICE9 dev, const std::vector<Vertex> &vertexes,
	const std::vector<WORD> &indexes, UINT primCount)
{
	dev->CreateVertexBuffer(vertexes.size() * sizeof(Vertex),
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
	memcpy(data, &vertexes[0], vertexes.size() * sizeof(Vertex));
	_vb->Unlock();

	if (&indexes)
	{
		dev->CreateIndexBuffer(
			indexes.size() * sizeof(WORD),
			D3DUSAGE_WRITEONLY,
			D3DFMT_INDEX16,
			D3DPOOL_MANAGED,
			&_ib,
			NULL
			);
		VOID *indexData;
		_ib->Lock(0, 0, &indexData, 0);
		memcpy(indexData, &indexes[0], indexes.size() * sizeof(WORD));
		_ib->Unlock();
	}

	_primitivesCount = primCount;
}

LPDIRECT3DVERTEXBUFFER9 Model::GetVertexBuffer()
{
	return _vb;
}

LPDIRECT3DINDEXBUFFER9 Model::GetIndexBuffer()
{
	return _ib;
}

std::vector<Vertex> Model::GetVertexes()
{
	return _vertexes;
}

std::vector<WORD> Model::GetIndexes()
{
	return _indexes;
}

UINT Model::GetPrimitivesCount()
{
	return _primitivesCount;
}