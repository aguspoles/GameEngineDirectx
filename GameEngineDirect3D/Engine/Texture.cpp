#include "stdafx.h"
#include "Texture.h"


Texture::Texture() : g_texture(NULL), _dev(NULL)
{

}

Texture::Texture(LPDIRECT3DDEVICE9 dev) : g_texture(NULL), _dev(dev)
{
	_adressU = D3DTADDRESS_WRAP;
	_adressV = D3DTADDRESS_WRAP;
	_magFilter = D3DTEXF_ANISOTROPIC;
	_minFilter = D3DTEXF_ANISOTROPIC;
	_mipFilter = D3DTEXF_ANISOTROPIC;
	_transformFlag = D3DTTFF_COUNT2;
}


Texture::~Texture()
{
}

void Texture::SetTexture(D3DXMATRIX* textureMatrix)
{
	_dev->SetTexture(0, g_texture);
	_dev->SetSamplerState(0, D3DSAMP_ADDRESSU, _adressU);//adress mode in u
	_dev->SetSamplerState(0, D3DSAMP_ADDRESSV, _adressV);//adress mode in v
	_dev->SetSamplerState(0, D3DSAMP_MINFILTER, _minFilter);//filter
	_dev->SetSamplerState(0, D3DSAMP_MAGFILTER, _magFilter);//filter
	_dev->SetSamplerState(0, D3DSAMP_MIPFILTER, _mipFilter);//filter
	_dev->SetTextureStageState(0, D3DTSS_TEXTURETRANSFORMFLAGS, _transformFlag);
	_dev->SetTransform(D3DTS_TEXTURE0, textureMatrix);
}

void Texture::LoadTexture(LPWSTR textureName)
{
	D3DXCreateTextureFromFile(_dev, textureName, &g_texture);
	_dev->SetTexture(0, g_texture);
}

void Texture::SetDevice(LPDIRECT3DDEVICE9 dev)
{
	_dev = dev;
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
