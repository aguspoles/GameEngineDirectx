#include "stdafx.h"
#include "Material.h"


Material::Material() : _blendEnable(false)
{
	D3DXMatrixIdentity(&_positionTexMatrix);
	D3DXMatrixIdentity(&_scaleTexMatrix);
	D3DXMatrixIdentity(&_rotateTexMatrix);
	D3DXMatrixIdentity(&_textureMatrix);
}

Material::Material(Texture * t, LPDIRECT3DDEVICE9 dev) : _blendEnable(false)
{
	D3DXMatrixIdentity(&_positionTexMatrix);
	D3DXMatrixIdentity(&_scaleTexMatrix);
	D3DXMatrixIdentity(&_rotateTexMatrix);
	D3DXMatrixIdentity(&_textureMatrix);

	_texture = t;
	_dev = dev;
}


Material::~Material()
{
	if (_texture)
	{
		delete _texture;
		_texture = NULL;
	}
}

void Material::SetDevice(LPDIRECT3DDEVICE9 dev)
{
	_dev = dev;
}

void Material::SetTexture(Texture * tex)
{
	_texture = tex;
}

LPDIRECT3DDEVICE9 Material::GetDevice()
{
	return _dev;
}

Texture * Material::GetTexture()
{
	return _texture;
}

D3DXMATRIX * Material::GetTextureMatrix()
{
	return &_textureMatrix;
}

void Material::Tiling(D3DXVECTOR3 scal)
{
	D3DXMatrixTranslation(&_positionTexMatrix, scal.x, scal.y, scal.z);
	_textureMatrix = _rotateTexMatrix * _scaleTexMatrix * _positionTexMatrix;
}

void Material::Offset(D3DXVECTOR2 pos)
{
	D3DXMatrixIdentity(&_positionTexMatrix);
		_positionTexMatrix._31 = pos.x;
		_positionTexMatrix._32 = pos.y;
		_textureMatrix = _rotateTexMatrix * _scaleTexMatrix * _positionTexMatrix;
}

void Material::RotateTexture(D3DXVECTOR3 rot)
{
	D3DXMATRIX rotX;
	D3DXMATRIX rotY;
	D3DXMATRIX rotZ;
	D3DXMatrixRotationZ(&rotZ, rot.z);
	D3DXMatrixRotationX(&rotX, rot.x);
	D3DXMatrixRotationY(&rotY, rot.y);
	_rotateTexMatrix = rotZ * rotX * rotY;
	_textureMatrix = _rotateTexMatrix * _scaleTexMatrix * _positionTexMatrix;
}

void Material::SetBlend()
{
	if (_blendEnable)
	{
		_dev->SetRenderState(D3DRS_ALPHABLENDENABLE, _blendEnable);
		_dev->SetRenderState(D3DRS_SRCBLEND, _srcFactor);
		_dev->SetRenderState(D3DRS_DESTBLEND, _destFactor);
		//_dev->SetRenderState(D3DRS_BLENDOP, _blendOP);
	}
}

void Material::AddBlending()
{
	_blendEnable = true;
	_srcFactor = D3DBLEND_ONE;
	_destFactor = D3DBLEND_ONE;
	//_blendOP = D3DBLENDOP_ADD;
}

void Material::AlphaBlending()
{
	_blendEnable = true;
	_srcFactor = D3DBLEND_SRCALPHA;
	_destFactor = D3DBLEND_INVSRCALPHA;
}

void Material::MultiBlending()
{
	_blendEnable = true;
	_srcFactor = D3DBLEND_DESTCOLOR;
	_destFactor = D3DBLEND_ZERO;
}
