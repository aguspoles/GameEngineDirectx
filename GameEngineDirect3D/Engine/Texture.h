#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>

class ENGINE_API Texture
{
private:
	IDirect3DTexture9* g_texture;
	LPDIRECT3DDEVICE9 _dev;
	D3DXMATRIX _textureMatrix;
	D3DXMATRIX _scaleMatrix;
	D3DXMATRIX _positionMatrix;
	D3DXMATRIX _rotateMatrix;
	D3DTEXTUREADDRESS _adressU;
	D3DTEXTUREADDRESS _adressV;
	D3DTEXTUREFILTERTYPE _magFilter;
	D3DTEXTUREFILTERTYPE _minFilter;
	D3DTEXTUREFILTERTYPE _mipFilter;
	D3DXVECTOR2 _offSet;
	D3DTEXTURETRANSFORMFLAGS _transformFlag;
public:
	Texture();
	Texture(LPDIRECT3DDEVICE9 dev);
	~Texture();

	void Update();

	void LoadTexture(LPWSTR textureName);
	void SetDevice(LPDIRECT3DDEVICE9 dev);

	void SetAdressModeU(D3DTEXTUREADDRESS adress);
	void SetAdressModeV(D3DTEXTUREADDRESS adress);
	void SetMagFilter(D3DTEXTUREFILTERTYPE filter);
	void SetMinFilter(D3DTEXTUREFILTERTYPE filter);
	void SetMipFilter(D3DTEXTUREFILTERTYPE filter);
	void SetTransformFlag(D3DTEXTURETRANSFORMFLAGS transformFlag);

	void Tiling(D3DTEXTUREADDRESS adressModeU, D3DTEXTUREADDRESS adressModeV);
	void Offset(D3DXVECTOR2 pos);

	void Rotate(float x, float y, float z);
	void Transalte(D3DXVECTOR3 pos);
	void Scale(D3DXVECTOR3 scal);

	void WaterEffect();
};

#endif