#include "stdafx.h"
#include "Material.h"


Material::Material() : _blendEnable(false)
{
	D3DXMatrixIdentity(&_positionTexMatrix);
	D3DXMatrixIdentity(&_scaleTexMatrix);
	D3DXMatrixIdentity(&_rotateTexMatrix);
	D3DXMatrixIdentity(&_textureMatrix);
}

Material::~Material()
{
	if (_texture)
		delete _texture;
}

D3DXMATRIX * Material::GetTextureMatrix()
{
	return &_textureMatrix;
}

void Material::SetTexture(Texture* texture)
{
	_texture = texture;
}

Texture * Material::GetTexture()
{
	return _texture;
}

void Material::Tiling(D3DXVECTOR3 scal)
{
	_textureMatrix._11 = scal.x;
	_textureMatrix._22 = scal.y;
	//D3DXMatrixIdentity(&_textureMatrix);
	//_textureMatrix = _rotateTexMatrix * _scaleTexMatrix * _positionTexMatrix;
}

void Material::Offset(D3DXVECTOR2 pos)
{
	_textureMatrix._31 = pos.x;
	_textureMatrix._32 = pos.y;
	//D3DXMatrixIdentity(&_textureMatrix);
		//_textureMatrix = _rotateTexMatrix * _scaleTexMatrix * _positionTexMatrix;
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
		GameSetUp::Device->SetRenderState(D3DRS_ALPHABLENDENABLE, _blendEnable);
		GameSetUp::Device->SetRenderState(D3DRS_SRCBLEND, _srcFactor);
		GameSetUp::Device->SetRenderState(D3DRS_DESTBLEND, _destFactor);
		//Game::Device->SetRenderState(D3DRS_BLENDOP, _blendOP);
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

void Material::SetShadder(LPCWSTR shader)
{
	D3DXCreateEffectFromFile(
		GameSetUp::Device, shader, NULL, NULL,
		D3DXSHADER_ENABLE_BACKWARDS_COMPATIBILITY,
		NULL, &_effect, NULL);
}

LPD3DXEFFECT Material::GetShadderEffect()
{
	return _effect;
}
