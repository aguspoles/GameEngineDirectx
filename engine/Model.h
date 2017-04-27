#pragma once
#include "Game.h"

#define CUSTOMFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

struct Vertex
{
	FLOAT x, y, z, rhw;
	DWORD color;
};

class Model
{
private:
	LPDIRECT3DVERTEXBUFFER9 vb;
	LPDIRECT3DINDEXBUFFER9 ib;
public:
	Model();
	Model(LPDIRECT3DDEVICE9 dev);
	LPDIRECT3DVERTEXBUFFER9 GetVertexBuffer();
	LPDIRECT3DINDEXBUFFER9 GetIndexBuffer();

	~Model();
};

