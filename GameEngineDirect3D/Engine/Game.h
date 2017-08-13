#ifndef GAME_H
#define GAME_H
#include <vector>
#include <chrono>
#include "Camera.h"
#include "Input.h"
#include "Material.h"

using namespace std::chrono;

class Entity;

class ENGINE_API Game
{
private:
	float _lastFrameMs;
	float _currentFrameMs;
	static float _deltaTime;
protected:
	LPDIRECT3D9 d3d;
	LPDIRECT3DDEVICE9 dev;
	std::vector<Entity*> _entities;
	std::vector<Material*> _materials;
	std::vector<Model*> _models;
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
	void AddMaterial(Material* m);
	void AddModel(Model* model);
	static int Time();
	static float DeltaTime();
};

#endif