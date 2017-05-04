#pragma once
#include "Game.h"
#include <vector>

#define CUSTOMFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

struct Vertex
{
	FLOAT x, y, z, rhw;
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

