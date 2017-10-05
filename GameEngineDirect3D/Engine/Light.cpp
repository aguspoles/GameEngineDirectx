#include "stdafx.h"
#include "Light.h"

D3DXVECTOR4 Light::_lightDir = D3DXVECTOR4();
D3DXVECTOR4 Light::_lightCol = D3DXVECTOR4();
D3DXVECTOR4 Light::_ambientCol = D3DXVECTOR4();

Light::Light()
{
}


Light::~Light()
{
}

void Light::SetLightDirection(D3DXVECTOR4 lightDir)
{
	_lightDir = lightDir;
}

void Light::SetLightColor(D3DXVECTOR4 lightCol)
{
	_lightCol = lightCol;
}

void Light::SetLightAmbientColor(D3DXVECTOR4 ambientCol)
{
	_ambientCol = ambientCol;
}

D3DXVECTOR4 Light::GetLightDirection()
{
	return _lightDir;
}

D3DXVECTOR4 Light::GetLightColor()
{
	return _lightCol;
}

D3DXVECTOR4 Light::GetLightAmbientColor()
{
	return _ambientCol;
}
