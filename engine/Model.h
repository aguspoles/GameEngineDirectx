#pragma once
#include "Game.h"

#define CUSTOMFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

class Model
{
private:
	LPDIRECT3DDEVICE9 _dev;
	struct Vertex
	{
		FLOAT x, y, z, rhw;
		DWORD color;
	};
	LPDIRECT3DVERTEXBUFFER9 vb;
	LPDIRECT3DINDEXBUFFER9 ib;
public:
	Model(LPDIRECT3DDEVICE9 dev);
	~Model();
};

