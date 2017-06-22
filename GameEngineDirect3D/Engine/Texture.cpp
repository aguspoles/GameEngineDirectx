#include "stdafx.h"
#include "Texture.h"


Texture::Texture() : g_texture(NULL), _dev(NULL), _offSet(0,0)
{
	D3DXMatrixIdentity(&_textureMatrix);
	D3DXMatrixIdentity(&_positionMatrix);
	D3DXMatrixIdentity(&_rotateMatrix);
	D3DXMatrixIdentity(&_scaleMatrix);
}

Texture::Texture(LPDIRECT3DDEVICE9 dev) : g_texture(NULL), _dev(dev), _offSet(0, 0)
{
	D3DXMatrixIdentity(&_textureMatrix);
	D3DXMatrixIdentity(&_positionMatrix);
	D3DXMatrixIdentity(&_rotateMatrix);
	D3DXMatrixIdentity(&_scaleMatrix);
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

void Texture::Update()
{
	_dev->SetTexture(0, g_texture);
	_dev->SetSamplerState(0, D3DSAMP_ADDRESSU, _adressU);//adress mode in u
	_dev->SetSamplerState(0, D3DSAMP_ADDRESSV, _adressV);//adress mode in v
	_dev->SetSamplerState(0, D3DSAMP_MINFILTER, _minFilter);//filter
	_dev->SetSamplerState(0, D3DSAMP_MAGFILTER, _magFilter);//filter
	_dev->SetSamplerState(0, D3DSAMP_MIPFILTER, _mipFilter);//filter
	_dev->SetTextureStageState(0, D3DTSS_TEXTURETRANSFORMFLAGS, _transformFlag);
	_dev->SetTransform(D3DTS_TEXTURE0, &(_textureMatrix));
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

void Texture::Tiling(D3DTEXTUREADDRESS adressModeU, D3DTEXTUREADDRESS adressModeV)
{
	_adressU = adressModeU;
	_adressV = adressModeV;
}

void Texture::Offset(D3DXVECTOR2 pos)
{
	_offSet = pos;
	D3DXMatrixIdentity(&_positionMatrix);
	_positionMatrix._31 = pos.x;
	_positionMatrix._32 = pos.y;
	_textureMatrix = _rotateMatrix * _scaleMatrix * _positionMatrix;
}

void Texture::Rotate(float x, float y, float z)
{
	D3DXMATRIX rotX;
	D3DXMATRIX rotY;
	D3DXMATRIX rotZ;
	D3DXMatrixIdentity(&_rotateMatrix);
	D3DXMatrixRotationX(&rotX, D3DXToRadian(x));
	D3DXMatrixRotationY(&rotY, D3DXToRadian(y));
	D3DXMatrixRotationZ(&rotZ, D3DXToRadian(z));
	_rotateMatrix = rotZ * rotX * rotY;
	_textureMatrix = _rotateMatrix * _scaleMatrix * _positionMatrix;
}

void Texture::Transalte(D3DXVECTOR3 pos)
{
	D3DXMatrixIdentity(&_positionMatrix);
	D3DXMatrixTranslation(&_positionMatrix, pos.x, pos.y, pos.z);
	_textureMatrix = _rotateMatrix * _scaleMatrix * _positionMatrix;
}

void Texture::Scale(D3DXVECTOR3 scal)
{
	D3DXMatrixIdentity(&_scaleMatrix);
	D3DXMatrixScaling(&_scaleMatrix, scal.x, scal.y, scal.z);
	_textureMatrix = _rotateMatrix * _scaleMatrix * _positionMatrix;
}

void Texture::WaterEffect()
{
	static float num = 0;
	D3DXMatrixIdentity(&_positionMatrix);
	D3DXMatrixIdentity(&_rotateMatrix);
	D3DXMatrixRotationZ(&_rotateMatrix, num);
	D3DXMatrixTranslation(&_positionMatrix, num, num, 0);
	_textureMatrix = _rotateMatrix * _scaleMatrix * _positionMatrix;
	num += 0.01;
}
