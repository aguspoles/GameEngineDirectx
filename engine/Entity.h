#pragma once
#include "Game.h"
#include "Model.h"

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
	void LoadModel(Model *m);
	void SetDevice(LPDIRECT3DDEVICE9 dev);

	D3DXMATRIX GetModelMatrix(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 sca);
};

