#pragma once
//#include "Camera.h"
//class Camera;

class ENGINE_API GameSetUp
{
private:
protected:
	//static Camera* _camera;
public:
	GameSetUp();
	~GameSetUp();

	static LPDIRECT3DDEVICE9 Device;
	virtual void InitD3D(_In_ HINSTANCE hInstance, _In_ int nCmdShow) = 0;

	//static Camera* GetCamera();
};

