#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "Component.h"

class ENGINE_API Transform : public Component
{
private:
	//model matrixes
	D3DXMATRIX _modelMatrix;
	D3DXMATRIX _rotateMeshMatrix;
	D3DXMATRIX _scaleMeshMatrix;
	D3DXMATRIX _translateMeshMatrix;
public:
	Transform();
	~Transform();
	D3DXVECTOR3 position;
	D3DXVECTOR3 rotation;
	D3DXVECTOR3 scale;

	void ModelMatrix(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 sca);//escala, rota y traslada
	D3DXMATRIX* GetModelMatrix();
	D3DXMATRIX* GetTranslateMeshMatrix();
	D3DXMATRIX* GetRotateMeshMatrix();
	D3DXMATRIX* GetScaleMeshMatrix();
	void SetModelMatrix(D3DXMATRIX model);
	void TranslateMesh(D3DXVECTOR3 pos);
	void RotateMesh(D3DXVECTOR3 rot);
	void ScaleMesh(D3DXVECTOR3 scal);

	void SetChildModel(Transform* child);
	void SetPosition(float x, float y, float z);

	void MoveForward(float vel);
	void MoveRight(float vel);
	void MoveLeft(float vel);
	void MoveBackWard(float vel);

	float GetForward();
	float GetUp();
	float GetRight();
};

#endif