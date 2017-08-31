#pragma once
class ENGINE_API GameSetUp
{
private:
public:
	GameSetUp();
	~GameSetUp();

	static LPDIRECT3DDEVICE9 Device;
	virtual void InitD3D(_In_ HINSTANCE hInstance, _In_ int nCmdShow) = 0;
};

