//#pragma once
#ifndef GAME_H
#define GAME_H
#include <vector>
#include "EngineApi.h"
#include "Camera.h"

class Entity;

class ENGINE_API Game
{
protected:
	std::vector<Entity*> entities;
	Camera* _camera;
public:
	Game();
    ~Game();

	void InitD3D(_In_ HINSTANCE hInstance, _In_ int nCmdShow);
	void RenderFrame();
	void Run(_In_ HINSTANCE hInstance, _In_ int nCmdShow);

	virtual void Init_Graphics() = 0;

	void AddEntitie(Entity e);
};

#endif