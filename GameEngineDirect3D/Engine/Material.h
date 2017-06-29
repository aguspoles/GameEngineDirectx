#ifndef MATERIAL_H
#define MATERIAL_H
#include "Model.h"
#include "Texture.h"

class ENGINE_API Material
{
private:
	Texture* _texture;
	LPDIRECT3DDEVICE9 _dev;

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
	Material(Texture* t, LPDIRECT3DDEVICE9 dev);
	~Material();

	void SetDevice(LPDIRECT3DDEVICE9 dev);
	void SetTexture(Texture* tex);

	LPDIRECT3DDEVICE9 GetDevice();
	Texture* GetTexture();

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