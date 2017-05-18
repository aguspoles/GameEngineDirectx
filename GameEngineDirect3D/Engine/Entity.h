//#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include "Model.h"
#include "Game.h"
#include "Transform.h"

class ENGINE_API Entity 
{
private:
	Model* _model;
	LPDIRECT3DDEVICE9 _dev;
	D3DXMATRIX _modelMatrix;
	D3DXMATRIX _rotateMatrix;
	D3DXMATRIX _scaleMatrix;
	D3DXMATRIX _translateMatrix;
	Transform _transform;
	
public:
	Entity();
	Entity(LPDIRECT3DDEVICE9 dev, Model *m);
    ~Entity();

	void Render();
	void LoadModel(Model *m);
	void SetDevice(LPDIRECT3DDEVICE9 dev);

	void ModelMatrix(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 sca);//escala, rota y traslada
	D3DXMATRIX GetModelMatrix();
	void SetModelMatrix(D3DXMATRIX model);
	void SetParent(Entity* parent);

	void Translate(D3DXVECTOR3 pos);
	void Rotate(D3DXVECTOR3 rot);
	void Scale(D3DXVECTOR3 scal);

	Transform GetTransform();
};

#endif

