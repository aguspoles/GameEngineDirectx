#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>

class ENGINE_API Texture
{
private:
	IDirect3DTexture9* g_texture;
	LPDIRECT3DDEVICE9 _dev;
	D3DTEXTUREADDRESS _adress;
	D3DTEXTUREFILTERTYPE _filter;
public:
	Texture();
	Texture(LPDIRECT3DDEVICE9 dev);
	~Texture();

	void Update();

	void LoadTexture(LPWSTR textureName);
	void SetDevice(LPDIRECT3DDEVICE9 dev);

	void SetAdressMode(D3DTEXTUREADDRESS adress);
	void SetFilter(D3DTEXTUREFILTERTYPE filter);

	void Tiling();
	void Offset(DWORD transformFlagValue, D3DXVECTOR2 pos);
};

#endif