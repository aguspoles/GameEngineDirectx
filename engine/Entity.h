#pragma once
#include "Game.h"
#include "Model.h"
#define CUSTOMFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

class Entity
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
	Entity(LPDIRECT3DDEVICE9 dev);
	virtual ~Entity();

    void Render();
	void LoadModel(Model &m);
	virtual void Clean();
};
