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
	std::vector<MeshRenderer*> entities = GetMeshes();
	for (std::vector<MeshRenderer*>::iterator it = entities.begin(); it != entities.end(); it++)
	{
		if (*it && (*it)->IsVisible())
		{
			(*it)->Update();
			if ((*it)->GetType() == "Player")
			{
				Player *p = (Player*)*it;
				p->EnemyCollision(entities);
			}
			if ((*it)->GetType() == "Enemy")
			{
				Enemy *e = (Enemy*)*it;
				e->Escape(entities);
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
		{ -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
		{ 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f },
		{ 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f },
		{ -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f }
	};

	std::vector<std::vector<int>> Map =
	{
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
		{ 0,0,0,0,0 },
	};
	Model* m = new Model(vertexes, indexes);
	//m->LoadModelFromFile("cube.obj");
	Texture* tex1 = new Texture();
	tex1->LoadTexture(L"../walk.png");
	Texture* tex2 = new Texture();
	tex2->LoadTexture(L"../metal.jpg");
	Texture* tex3 = new Texture();
	tex3->LoadTexture(L"../particle.png");

	Material* mat = new Material();
	mat->SetTexture(tex3);
	//mat->SetShadder(L"shaderTexTinte.fx");
	Material* mat1 = new Material();
	mat1->SetTexture(tex1);
	mat1->SetShadder(L"shaderTexTinte.fx");
	Material* mat2 = new Material();
	mat2->SetTexture(tex2);

	_tileMap = new TileMap(Map, 0.5f, 0.5f);
	Floor* f = new Floor();
	_tileMap->AddTile(f);
	Player* p = new Player();
	Enemy* e = new Enemy();
	PickUp* pick = new PickUp();


	Animation* anim = new Animation("Run", mat1, 240, 296, 1440, 1480);

	//seteo player
	p->SetModel(m);
	p->Add(mat1);
    p->AddAnimation(anim);
	p->SetCurrentAnimation("Run", 0.08);

	//seteo enemigo
	e->SetModel(m);
	e->Add(mat);
	e->SetParent(pick);

	//seteo pick
	pick->SetModel(m);
	pick->Add(mat1);
	pick->SetParent(p);

	//seteo floor
	f->SetModel(m);
	f->Add(mat2);

	AddEntitie(e);
	AddEntitie(p);
	AddEntitie(pick);
	AddMaterial(mat);
	AddMaterial(mat1);
	AddMaterial(mat2);
	AddModel(m);

	for each(MeshRenderer* entitie in GetMeshes())
	{
		if (entitie)
			entitie->Init();
	}

	SetCamera();
}


void GameApp::SetCamera()
{
	Camera::Instance()->SetViewMatrix(D3DXVECTOR3(0, 0, 10), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 1, 0));
	Camera::Instance()->SetPerspective(60, (float)640 / (float)480, 0.0f, 100.0f);
	Camera::Instance()->SetRenderView();
}
