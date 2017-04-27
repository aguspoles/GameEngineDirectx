#pragma once
#include "Entity.h"
#define CUSTOMFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_NORMAL | D3DFVF_TEX0)

class Player : public Entity
{
private:
		struct Vertex
		{
			FLOAT x, y, z, rhw;
			DWORD color;
		};
	LPDIRECT3DVERTEXBUFFER9 vb;
	LPDIRECT3DINDEXBUFFER9 ib;

public:
	Player(LPDIRECT3DDEVICE9 dev);
	~Player();

    void Entity::Render(LPDIRECT3DDEVICE9 dev);
	void Entity::Clean();
};

