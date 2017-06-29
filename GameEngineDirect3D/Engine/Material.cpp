#include "stdafx.h"
#include "Material.h"


Material::Material()
{
    D3DXMatrixIdentity(&_rotateMeshMatrix);
	D3DXMatrixIdentity(&_scaleMeshMatrix);
	D3DXMatrixIdentity(&_translateMeshMatrix);
	D3DXMatrixIdentity(&_modelMatrix);

	D3DXMatrixIdentity(&_positionTexMatrix);
	D3DXMatrixIdentity(&_scaleTexMatrix);
	D3DXMatrixIdentity(&_rotateTexMatrix);
	D3DXMatrixIdentity(&_textureMatrix);

	TranslateMesh(D3DXVECTOR3(0, 0, 1));
}

Material::Material(Model * m, Texture * t, LPDIRECT3DDEVICE9 dev)
{
	D3DXMatrixIdentity(&_rotateMeshMatrix);
	D3DXMatrixIdentity(&_scaleMeshMatrix);
	D3DXMatrixIdentity(&_translateMeshMatrix);
	D3DXMatrixIdentity(&_modelMatrix);

	D3DXMatrixIdentity(&_positionTexMatrix);
	D3DXMatrixIdentity(&_scaleTexMatrix);
	D3DXMatrixIdentity(&_rotateTexMatrix);
	D3DXMatrixIdentity(&_textureMatrix);

	_model = m;
	_texture = t;
	_dev = dev;

	TranslateMesh(D3DXVECTOR3(0, 0, 1));
}


Material::~Material()
{
	if (_texture)
	{
		delete _texture;
		_texture = NULL;
	}
	if (_model)
	{
		delete _model;
		_model = NULL;
	}
}

void Material::LoadModel(Model * m)
{
	_model = m;
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

Model * Material::GetModel()
{
	return _model;
}

void Material::ModelMatrix(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 sca)
{
	D3DXMATRIX rotX;
	D3DXMATRIX rotY;
	D3DXMATRIX rotZ;
	D3DXMatrixRotationZ(&rotZ, rot.z);
	D3DXMatrixRotationX(&rotX, rot.x);
	D3DXMatrixRotationY(&rotY, rot.y);
	D3DXMatrixScaling(&_scaleMeshMatrix, sca.x, sca.y, sca.z);
	D3DXMatrixTranslation(&_translateMeshMatrix, pos.x, pos.y, pos.z);
	_rotateMeshMatrix = rotZ * rotX * rotY;
	_modelMatrix = _scaleMeshMatrix * _rotateMeshMatrix * _translateMeshMatrix;
}

D3DXMATRIX* Material::GetModelMatrix()
{
	return &_modelMatrix;
}

D3DXMATRIX * Material::GetTranslateMeshMatrix()
{
	return &_translateMeshMatrix;
}

D3DXMATRIX * Material::GetRotateMeshMatrix()
{
	return &_rotateMeshMatrix;
}

D3DXMATRIX * Material::GetScaleMeshMatrix()
{
	return &_scaleMeshMatrix;
}

void Material::SetModelMatrix(D3DXMATRIX model)
{
	_modelMatrix = model;
}

void Material::TranslateMesh(D3DXVECTOR3 pos)
{
	D3DXMatrixTranslation(&_translateMeshMatrix , pos.x,
		pos.y,
		pos.z);
	_modelMatrix = _rotateMeshMatrix * _scaleMeshMatrix * _translateMeshMatrix;
}

void Material::RotateMesh(D3DXVECTOR3 rot)
{
	D3DXMATRIX rotX;
	D3DXMATRIX rotY;
	D3DXMATRIX rotZ;
	D3DXMatrixRotationZ(&rotZ, rot.z);
	D3DXMatrixRotationX(&rotX, rot.x);
	D3DXMatrixRotationY(&rotY, rot.y);
	_rotateMeshMatrix = rotZ * rotX * rotY;
	_modelMatrix = _rotateMeshMatrix * _scaleMeshMatrix * _translateMeshMatrix;
}

void Material::ScaleMesh(D3DXVECTOR3 scal)
{
	D3DXMatrixScaling(&_scaleMeshMatrix, scal.x, scal.y, scal.z);
	_modelMatrix = _rotateMeshMatrix * _scaleMeshMatrix * _translateMeshMatrix;
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
	_dev->SetRenderState(D3DRS_ALPHABLENDENABLE, _blendEnable);
	_dev->SetRenderState(D3DRS_SRCBLEND, _srcFactor);
	_dev->SetRenderState(D3DRS_DESTBLEND, _destFactor);
	//_dev->SetRenderState(D3DRS_BLENDOP, _blendOP);
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
