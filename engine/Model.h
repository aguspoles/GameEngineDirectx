#pragma once
#include "Game.h"
#include <d3dx9.h>
#include <vector>

#define CUSTOMFVF (D3DFVF_XYZ | D3DFVF_DIFFUSE)

struct Vertex
{
	FLOAT x, y, z;
	DWORD color;
};

class Model
{
private:
	LPDIRECT3DVERTEXBUFFER9 _vb;
	LPDIRECT3DINDEXBUFFER9 _ib;
public:
	Model();
	Model(LPDIRECT3DDEVICE9 dev, Vertex vertexes[], WORD indexes[], 
		int vertexesSize, int indexesSize);

	LPDIRECT3DVERTEXBUFFER9 GetVertexBuffer();
	LPDIRECT3DINDEXBUFFER9 GetIndexBuffer();

	~Model();
};

