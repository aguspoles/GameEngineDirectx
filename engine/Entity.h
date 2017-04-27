#pragma once
#include "Game.h"

class Entity
{
public:
	Entity();
	virtual ~Entity();

    virtual void Render(LPDIRECT3DDEVICE9 dev)=0;
	virtual void Clean()=0;
};

