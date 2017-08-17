#ifndef ENTITY_H
#define ENTITY_H
#include "Game.h"
#include "Transform.h"
#include "Material.h"

class ENGINE_API Entity 
{
private:
	Model* _model;
	Material* _material;
	Transform _transform;
	LPDIRECT3DDEVICE9 _dev;
	bool _isVisible;

	//model matrixes
	D3DXMATRIX _modelMatrix;
	D3DXMATRIX _rotateMeshMatrix;
	D3DXMATRIX _scaleMeshMatrix;
	D3DXMATRIX _translateMeshMatrix;
	
public:
	Entity();
	Entity(LPDIRECT3DDEVICE9 dev);
    ~Entity();

	virtual void Init() = 0;
	virtual void Update() = 0;
	void Render();

	Material* GetMaterial();
	void SetMaterial(Material* m);

	void SetDevice(LPDIRECT3DDEVICE9 dev);
	LPDIRECT3DDEVICE9 GetDevice();

	Model* GetModel();
	void LoadModel(Model *m);

	void ModelMatrix(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 sca);//escala, rota y traslada
	D3DXMATRIX* GetModelMatrix();
	D3DXMATRIX* GetTranslateMeshMatrix();
	D3DXMATRIX* GetRotateMeshMatrix();
	D3DXMATRIX* GetScaleMeshMatrix();
	void SetModelMatrix(D3DXMATRIX model);
	void TranslateMesh(D3DXVECTOR3 pos);
	void RotateMesh(D3DXVECTOR3 rot);
	void ScaleMesh(D3DXVECTOR3 scal);

	Transform GetTransform();

	void SetChildModel(Entity* child);

	void SetPosition(float x, float y, float z);

	void MoveForward();
	void MoveRight();
	void MoveLeft();
	void MoveBackWard();

	float GetForward();
	float GetUp();
	float GetRight();

	bool IsVisible() const;
	virtual std::string GetType() const=0;

};

#endif

