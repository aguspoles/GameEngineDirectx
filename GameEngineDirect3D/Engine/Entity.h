#ifndef ENTITY_H
#define ENTITY_H
#include "Model.h"
#include "Game.h"
#include "Transform.h"
#include "Texture.h"

class ENGINE_API Entity 
{
private:
	Model* _model;
	Texture* _texture;
	LPDIRECT3DDEVICE9 _dev;
	Transform _transform;
	bool _isVisible;
	D3DXMATRIX _modelMatrix;
	D3DXMATRIX _rotateMatrix;
	D3DXMATRIX _scaleMatrix;
	D3DXMATRIX _translateMatrix;
	
public:
	Entity();
	Entity(LPDIRECT3DDEVICE9 dev, Model *m);
    ~Entity();

	virtual void Update() = 0;
	void Render();

	void LoadModel(Model *m);
	void SetDevice(LPDIRECT3DDEVICE9 dev);
	LPDIRECT3DDEVICE9 GetDevice();
	void SetTexture(Texture* tex);

	void ModelMatrix(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 sca);//escala, rota y traslada
	D3DXMATRIX GetModelMatrix();
	void SetModelMatrix(D3DXMATRIX model);
	void SetParent(Entity* parent);

	Transform GetTransform();

	void Translate(D3DXVECTOR3 pos);
	void Rotate(D3DXVECTOR3 rot);
	void Scale(D3DXVECTOR3 scal);

	void MoveForward();
	void MoveRight();
	void MoveLeft();

	float GetForward();
	float GetUp();
	float GetRight();

	bool IsVisible() const;
	virtual std::string GetType() const=0;

};

#endif

