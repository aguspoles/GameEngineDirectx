#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>
#include "Component.h"
#include "GameSetUp.h"

class ENGINE_API Texture : public Component
{
private:
	IDirect3DTexture9* g_texture;
	D3DTEXTUREADDRESS _adressU;
	D3DTEXTUREADDRESS _adressV;
	D3DTEXTUREFILTERTYPE _magFilter;
	D3DTEXTUREFILTERTYPE _minFilter;
	D3DTEXTUREFILTERTYPE _mipFilter;
	D3DTEXTURETRANSFORMFLAGS _transformFlag;
public:
	Texture();
	~Texture();

	void SetTexture(D3DXMATRIX* textureMatrix);

	void LoadTexture(LPWSTR textureName);

	void SetAdressModeU(D3DTEXTUREADDRESS adress);
	void SetAdressModeV(D3DTEXTUREADDRESS adress);
	void SetMagFilter(D3DTEXTUREFILTERTYPE filter);
	void SetMinFilter(D3DTEXTUREFILTERTYPE filter);
	void SetMipFilter(D3DTEXTUREFILTERTYPE filter);
	void SetTransformFlag(D3DTEXTURETRANSFORMFLAGS transformFlag);
};

#endif