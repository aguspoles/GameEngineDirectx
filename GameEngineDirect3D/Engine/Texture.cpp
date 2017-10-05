#include "stdafx.h"
#include "Texture.h"


Texture::Texture() : g_texture(NULL)
{
	_adressU = D3DTADDRESS_WRAP;
	_adressV = D3DTADDRESS_WRAP;
	_magFilter = D3DTEXF_LINEAR;
	_minFilter = D3DTEXF_LINEAR;
	_mipFilter = D3DTEXF_NONE;
	_transformFlag = D3DTTFF_COUNT2;
}


Texture::~Texture()
{
}

void Texture::SetTexture(D3DXMATRIX* textureMatrix)
{
	GameSetUp::Device->SetTexture(0, g_texture);
	GameSetUp::Device->SetSamplerState(0, D3DSAMP_ADDRESSU, _adressU);//adress mode in u
	GameSetUp::Device->SetSamplerState(0, D3DSAMP_ADDRESSV, _adressV);//adress mode in v
	GameSetUp::Device->SetSamplerState(0, D3DSAMP_MINFILTER, _minFilter);//filter
	GameSetUp::Device->SetSamplerState(0, D3DSAMP_MAGFILTER, _magFilter);//filter
	GameSetUp::Device->SetSamplerState(0, D3DSAMP_MIPFILTER, _mipFilter);//filter
	GameSetUp::Device->SetTextureStageState(0, D3DTSS_TEXTURETRANSFORMFLAGS, _transformFlag);
	GameSetUp::Device->SetTransform(D3DTS_TEXTURE0, textureMatrix);
}

void Texture::LoadTexture(LPWSTR textureName)
{
	D3DXCreateTextureFromFile(GameSetUp::Device, textureName, &g_texture);
	GameSetUp::Device->SetTexture(0, g_texture);
}

void Texture::SetAdressModeU(D3DTEXTUREADDRESS adress)
{
	_adressU = adress;
}

void Texture::SetAdressModeV(D3DTEXTUREADDRESS adress)
{
	_adressV = adress;
}

void Texture::SetMagFilter(D3DTEXTUREFILTERTYPE filter)
{
	_magFilter = filter;
}

void Texture::SetMinFilter(D3DTEXTUREFILTERTYPE filter)
{
	_minFilter = filter;
}

void Texture::SetMipFilter(D3DTEXTUREFILTERTYPE filter)
{
	_mipFilter = filter;
}

void Texture::SetTransformFlag(D3DTEXTURETRANSFORMFLAGS transformFlag)
{
	_transformFlag = transformFlag;
}

IDirect3DTexture9* Texture::GetTexture()
{
	return g_texture;
}
