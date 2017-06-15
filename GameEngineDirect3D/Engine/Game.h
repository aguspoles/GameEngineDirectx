#ifndef GAME_H
#define GAME_H
#include <vector>
#include "Camera.h"
#include "Input.h"

class Entity;

class ENGINE_API Game
{
private:
	static Input* _input;
protected:
	LPDIRECT3D9 d3d;
	LPDIRECT3DDEVICE9 dev;
	std::vector<Entity*> _entities;
	Camera* _camera;
public:
	Game();
    ~Game();

	void InitD3D(_In_ HINSTANCE hInstance, _In_ int nCmdShow);
	void RenderFrame();
	virtual void Update()=0;
	virtual void Run(_In_ HINSTANCE hInstance, _In_ int nCmdShow)=0;

	static Input* GetInput();
	void AddEntitie(Entity* e);
};

#endif