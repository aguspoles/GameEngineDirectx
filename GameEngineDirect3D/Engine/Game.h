#ifndef GAME_H
#define GAME_H
#include <vector>
#include <chrono>
#include "Entity.h"
#include "TileMap.h"
#include "Camera.h"
#include "Input.h"
#include "Material.h"
#include "Model.h"

using namespace std::chrono;

class ENGINE_API Game
{
private:
	float _lastFrameMs;
	float _currentFrameMs;
	static float _deltaTime;
	LPDIRECT3D9 d3d;
protected:
	LPDIRECT3DDEVICE9 _dev;
	std::vector<Entity*> _entities;
	std::vector<Material*> _materials;
	std::vector<Model*> _models;
	Camera* _camera;
	TileMap* _tileMap;
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