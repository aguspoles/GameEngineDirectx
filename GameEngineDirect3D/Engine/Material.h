#ifndef MATERIAL_H
#define MATERIAL_H
#include "GameSetUp.h"
#include "Texture.h"
#include <map>
#include <string>
#include "Component.h"

class ENGINE_API Material : public Component
{
private:
	Texture* _texture;

	//shadder
	LPD3DXEFFECT _effect;
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
	~Material();

	D3DXMATRIX* GetTextureMatrix();
	void SetTexture(Texture* texture);
	Texture* GetTexture();

	void Tiling(D3DXVECTOR3 scal);//scale the texture
	void Offset(D3DXVECTOR2 pos);//positionate the texture
	void RotateTexture(D3DXVECTOR3 rot);

	void SetBlend();
	void AddBlending();
	void AlphaBlending();
	void MultiBlending();

	void SetShadder(LPCWSTR shader);
	LPD3DXEFFECT GetShadderEffect();
};

#endif