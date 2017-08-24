#include "stdafx.h"
#include "GameApp.h"

#define CANT 1
float num = 0;
float vel = 0.01;

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
	std::vector<WORD> indexes = { 0,1,2,3,0,2 };

	std::vector<Vertex> vertexes =
	{
		{ -1.0f, 1.0f, 0.0f, 0.0f, 0.0f },
		{ 1.0f, 1.0f, 0.0f, 1.0f, 0.0f },
		{ 1.0f, -1.0f, 0.0f, 1.0f, 1.0f },
		{ -1.0f, -1.0f, 0.0f, 0.0f, 1.0f }
	};

	Player* p = new Player(dev);
	Enemy* e = new Enemy(dev);
	PickUp* pick = new PickUp(dev);

	Model* m = new Model(dev, vertexes, indexes, 2);
	Texture* tex1 = new Texture(dev);
	tex1->LoadTexture(L"../walk.png");
	Texture* tex2 = new Texture(dev);
	tex2->LoadTexture(L"../metal.jpg");
	Texture* tex3 = new Texture(dev);
	tex3->LoadTexture(L"../particle.png");

	Material* mat = new Material(tex3, dev);
	Material* mat1 = new Material(tex1, dev);

	Animation* anim = new Animation("Run", mat1, 240, 296, 1440, 1480);

	//seteo player
	p->LoadModel(m);
	p->SetMaterial(mat1);
	p->AddAnimation(anim);
	p->SetCurrentAnimation("Run", 0.12);

	//seteo enemigo
	e->LoadModel(m);
	e->SetMaterial(mat);

	//seteo pick
	pick->LoadModel(m);
	pick->SetMaterial(mat);

	AddEntitie(e);
	AddEntitie(p);
	AddEntitie(pick);
	AddMaterial(mat);
	AddMaterial(mat1);
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
	_camera->GetViewMatrix(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0));
	_camera->SetPerspective(60, (float)640 / (float)480, 0.0f, 10.0f);
	_camera->SetRenderView(dev);
}
