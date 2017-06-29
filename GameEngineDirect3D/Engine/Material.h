#ifndef MATERIAL_H
#define MATERIAL_H
#include "Model.h"
#include "Texture.h"

class ENGINE_API Material
{
private:
	Model* _model;
	Texture* _texture;
	LPDIRECT3DDEVICE9 _dev;

	//model matrixes
	D3DXMATRIX _modelMatrix;
	D3DXMATRIX _rotateMeshMatrix;
	D3DXMATRIX _scaleMeshMatrix;
	D3DXMATRIX _translateMeshMatrix;
	//texture matrixes
	D3DXMATRIX _textureMatrix;
	D3DXMATRIX _scaleTexMatrix;
	D3DXMATRIX _positionTexMatrix;
	D3DXMATRIX _rotateTexMatrix;
	//blend
	DWORD _srcFactor;
	DWORD _destFactor;
	DWORD _blendOP;
	bool _blendEnable;

public:
	Material();
	Material(Model* m, Texture* t, LPDIRECT3DDEVICE9 dev);
	~Material();

	void LoadModel(Model *m);
	void SetDevice(LPDIRECT3DDEVICE9 dev);
	void SetTexture(Texture* tex);

	LPDIRECT3DDEVICE9 GetDevice();
	Texture* GetTexture();
	Model* GetModel();

	void ModelMatrix(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 sca);//escala, rota y traslada
	D3DXMATRIX* GetModelMatrix();
	D3DXMATRIX* GetTranslateMeshMatrix();
	D3DXMATRIX* GetRotateMeshMatrix();
	D3DXMATRIX* GetScaleMeshMatrix();
	void SetModelMatrix(D3DXMATRIX model);
	void TranslateMesh(D3DXVECTOR3 pos);
	void RotateMesh(D3DXVECTOR3 rot);
	void ScaleMesh(D3DXVECTOR3 scal);

	D3DXMATRIX* GetTextureMatrix();

	void Tiling(D3DXVECTOR3 scal);//scale the texture
	void Offset(D3DXVECTOR2 pos);//positionate the texture
	void RotateTexture(D3DXVECTOR3 rot);

	void SetBlend();
	void AddBlending();
	void AlphaBlending();
	void MultiBlending();
};

#endif