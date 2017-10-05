#pragma once
#include "Component.h"

class ENGINE_API Light :
	public Component
{
private:
	static D3DXVECTOR4 _lightDir;
	static D3DXVECTOR4 _lightCol;
	static D3DXVECTOR4 _ambientCol;
public:
	Light();
	~Light();

	static void SetLightDirection(D3DXVECTOR4 lightDir);
	static void SetLightColor(D3DXVECTOR4 lightCol);
	static void SetLightAmbientColor(D3DXVECTOR4 ambientCol);

	static D3DXVECTOR4 GetLightDirection();
	static D3DXVECTOR4 GetLightColor();
	static D3DXVECTOR4 GetLightAmbientColor();
};

