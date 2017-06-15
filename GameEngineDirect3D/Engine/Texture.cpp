#include "stdafx.h"
#include "Texture.h"


Texture::Texture() : g_texture(NULL), _dev(NULL)
{

}

Texture::Texture(LPDIRECT3DDEVICE9 dev) : g_texture(NULL), _dev(dev)
{
	_adress = D3DTADDRESS_WRAP;
	_filter = D3DTEXF_ANISOTROPIC;
}


Texture::~Texture()
{
}

void Texture::Update()
{
	static float num = 0;
	_dev->SetTexture(0, g_texture);
	Offset(D3DTTFF_COUNT2, D3DXVECTOR2(num,num));
	_dev->SetSamplerState(0, D3DSAMP_ADDRESSU, _adress);//adress mode in u
	_dev->SetSamplerState(0, D3DSAMP_ADDRESSV, _adress);//adress mode in v
	_dev->SetSamplerState(0, D3DSAMP_MINFILTER, _filter);//filter
	_dev->SetSamplerState(0, D3DSAMP_MAGFILTER, _filter);//filter
	_dev->SetSamplerState(0, D3DSAMP_MIPFILTER, _filter);//filter
	num += 0.01;
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

void Texture::SetAdressMode(D3DTEXTUREADDRESS adress)
{
	_adress = adress;
}

void Texture::SetFilter(D3DTEXTUREFILTERTYPE filter)
{
	_filter = filter;
}

void Texture::Tiling()
{
}

void Texture::Offset(DWORD transformFlagValue, D3DXVECTOR2 pos)
{
	static float num = 0;
	D3DXMATRIX trans;
	D3DXMATRIX rot;
	D3DXMatrixIdentity(&trans);
	D3DXMatrixIdentity(&rot);
	D3DXMatrixRotationZ(&rot, num);
	D3DXMatrixTranslation(&trans, num, num, 0);
	_dev->SetTextureStageState(0, D3DTSS_TEXTURETRANSFORMFLAGS, transformFlagValue);
	_dev->SetTransform(D3DTS_TEXTURE0, &(trans*rot));
	num += 0.01;
}
