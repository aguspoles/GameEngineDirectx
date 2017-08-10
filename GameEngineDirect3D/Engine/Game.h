#ifndef GAME_H
#define GAME_H
#include <vector>
#include "Camera.h"
#include "Input.h"

class Entity;

class ENGINE_API Game
{
private:
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
	virtual void Init()=0;
	virtual void Update()=0;
    void Run(_In_ HINSTANCE hInstance, _In_ int nCmdShow);

	void AddEntitie(Entity* e);
};

#endif