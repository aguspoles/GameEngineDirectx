#include "stdafx.h"
#include "GameApp.h"


GameApp::GameApp() 
{
}

GameApp::~GameApp()
{
}


void GameApp::Update()
{
	for (std::vector<Entity*>::iterator it = _entities.begin(); it != _entities.end(); it++)
	{
		if (*it && (*it)->IsVisible())
		{
			(*it)->Update();
			if ((*it)->GetType() == "Player")
			{
				Player *p = (Player*)*it;
				p->EnemyCollision(_entities);
			}
			if ((*it)->GetType() == "Enemy")
			{
				Enemy *e = (Enemy*)*it;
				e->Escape(_entities);
			}
		}
		else
		{
			delete *it;
			*it = NULL;
		}
	}
}

void GameApp::Init()
{
	std::vector<WORD> indexes = { 3,0,1,3,1,2 };

	std::vector<Vertex> vertexes =
	{
		{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		{ 0.5f, 0.0f, 0.0f, 1.0f, 0.0f },
		{ 0.5f, 0.5f, 0.0f, 1.0f, 1.0f },
		{ 0.0f, 0.5f, 0.0f, 0.0f, 1.0f }
	};
	std::vector<std::vector<int>> Map =
	{
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
	};
	_tileMap = new TileMap(Map, 0.5f, 0.5f);
	Floor* f = new Floor(_dev);
	_tileMap->AddTile(f);
	Player* p = new Player(_dev);
	Enemy* e = new Enemy(_dev);
	PickUp* pick = new PickUp(_dev);

	Model* m = new Model(_dev, vertexes, indexes, 2);
	Texture* tex1 = new Texture(_dev);
	tex1->LoadTexture(L"../walk.png");
	Texture* tex2 = new Texture(_dev);
	tex2->LoadTexture(L"../metal.jpg");
	Texture* tex3 = new Texture(_dev);
	tex3->LoadTexture(L"../particle.png");

	Material* mat = new Material(tex3, _dev);
	Material* mat1 = new Material(tex1, _dev);
	Material* mat2 = new Material(tex2, _dev);

	Animation* anim = new Animation("Run", mat1, 240, 296, 1440, 1480);

	//seteo player
	p->LoadModel(m);
	p->SetMaterial(mat1);
	p->AddAnimation(anim);
	p->SetCurrentAnimation("Run", 0.10);

	//seteo enemigo
	e->LoadModel(m);
	e->SetMaterial(mat);

	//seteo pick
	pick->LoadModel(m);
	pick->SetMaterial(mat);

	//seteo floor
	f->LoadModel(m);
	f->SetMaterial(mat2);

	AddEntitie(e);
	AddEntitie(p);
	AddEntitie(pick);
	AddMaterial(mat);
	AddMaterial(mat1);
	AddMaterial(mat2);
	AddModel(m);

	for each(Entity* entitie in _entities)
	{
		if (entitie)
			entitie->Init();
	}

	SetCamera();
}


void GameApp::SetCamera()
{
	_camera->SetViewMatrix(D3DXVECTOR3(0, 0, 10), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 1, 0));
	_camera->SetPerspective(60, (float)640 / (float)480, 0.0f, 100.0f);
	_camera->SetRenderView(_dev);
}
