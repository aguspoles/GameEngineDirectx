#ifndef GAME_H
#define GAME_H
#include <vector>
#include <chrono>
#include "GameSetUp.h"
#include "MeshRenderer.h"
#include "TileMap.h"
//#include "Camera.h"
#include "Input.h"
#include "Material.h"
#include "Model.h"

using namespace std::chrono;

class ENGINE_API Game : public GameSetUp
{
private:
	LPDIRECT3D9 d3d;
	std::vector<MeshRenderer*> _entities;
	std::vector<Material*> _materials;
	std::vector<Model*> _models;
	float _lastFrameMs;
	float _currentFrameMs;
	static float _deltaTime;
protected:
	TileMap* _tileMap;
    //Camera* _camera;
public:
	Game();
    ~Game();

	void InitD3D(_In_ HINSTANCE hInstance, _In_ int nCmdShow) override final;
	void RenderFrame();
	virtual void Init()=0;
	virtual void Update()=0;
    void Run(_In_ HINSTANCE hInstance, _In_ int nCmdShow);

	void AddEntitie(MeshRenderer* e);
	void AddMaterial(Material* m);
	void AddModel(Model* model);
	static int Time();
	static float DeltaTime();

	std::vector<MeshRenderer*> GetMeshes();
	//Camera* GetCamera();
};

#endif