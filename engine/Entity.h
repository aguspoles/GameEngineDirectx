#pragma once
#include "Game.h"
#include "Model.h"
#define CUSTOMFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

class Entity
{
private:
	Model* _m;
	LPDIRECT3DDEVICE9 _dev;
public:
	Entity();
	Entity(LPDIRECT3DDEVICE9 dev, Model *m);
	virtual ~Entity();

    void Render();
	void LoadModel(Model &m);
	void SetDevice(LPDIRECT3DDEVICE9 dev);
};

