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
				//e->Escape(entities);
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
		{ -1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f },
		{ 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f },
		{ 1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f },
		{ -1.0f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f }
	};

	Model* m = new Model(vertexes, indexes);
	Model* m1 = new Model();
	m1->LoadModelFromFile("bb8.obj");
	Texture* tex1 = new Texture();
	tex1->LoadTexture(L"../walk.png");
	Texture* tex2 = new Texture();
	tex2->LoadTexture(L"../metal.jpg");
	Texture* tex3 = new Texture();
	//tex3->LoadTexture(L"../particle.png");
	tex3->LoadTexture(L"../Body.jpg");
	Material* mat = new Material();
	mat->SetTexture(tex3);
	mat->SetShadder(L"efecto.fx");
	Material* mat1 = new Material();
	mat1->SetTexture(tex1);
	mat1->SetShadder(L"shaderTexTinte.fx");
	//mat1->SetShadder(L"efecto.fx");
	Material* mat2 = new Material();
	mat2->SetTexture(tex2);
	mat2->SetShadder(L"efecto.fx");

	std::vector<std::vector<int>> Map =
	{
		{ 0,1,0,1,0 },
		{ 1,0,1,0,1 },
		{ 0,1,0,1,0 },
	};
	_tileMap = new TileMap(Map, 0.5f, 0.5f);
	Tile* f = new Floor();
	Tile* f1 = new Floor();
	f->SetModel(m);
	f->AddComponent(mat2);
	f1->SetModel(m);
	f1->AddComponent(mat1);
	_tileMap->AddTile(f);
	_tileMap->AddTile(f1);

	Player* p = new Player();
	Enemy* e = new Enemy();
	PickUp* pick = new PickUp();


	Animation* anim = new Animation("Run", mat1, 240, 296, 1440, 1480);
	vector<frame> frames = {
	    frame(0,0), frame(0,1), frame(0,2), frame(0,3), frame(0,4), frame(0,5),
		frame(1,0), frame(1,1), frame(1,2), frame(1,3), frame(1,4), frame(1,5),
		frame(2,0), frame(2,1), frame(2,2), frame(2,3), frame(2,4), frame(2,5),
		frame(3,0), frame(3,1), frame(3,2), frame(3,3), frame(3,4), frame(3,5),
		frame(4,0), frame(4,1), frame(4,2), frame(4,3), frame(4,4), frame(4,5) };
	anim->SetFrames(frames);
	anim->SetIdleFrame(frame(0, 0));


	//seteo player
	p->SetModel(m);
	p->AddComponent(mat1);
    p->AddAnimation(anim);
	p->SetCurrentAnimation("Run", 0.08);

	//seteo enemigo
	e->SetModel(m1);
	e->AddComponent(mat);
	//e->SetParent(pick);

	//seteo pick
	pick->SetModel(m);
	pick->AddComponent(mat1);
	pick->SetParent(p);
	//pick->Add(e);


	AddEntitie(e);
	AddEntitie(p);
	AddEntitie(pick);
	AddMaterial(mat);
	AddMaterial(mat1);
	AddMaterial(mat2);
	AddModel(m);
	AddModel(m1);

	for each(MeshRenderer* entitie in GetMeshes())
	{
		if (entitie)
			entitie->Init();
	}

	SetCamera();
	SetLight();
}


void GameApp::SetCamera()
{
	Camera::Instance()->SetViewMatrix(D3DXVECTOR3(0, 0, 10), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 1, 0));
	Camera::Instance()->SetPerspective(60, (float)640 / (float)480, 0.0f, 100.0f);
	Camera::Instance()->SetRenderView();
}

void GameApp::SetLight()
{
	Light::SetLightDirection(D3DXVECTOR4(0, 0, 1, 0));
	Light::SetLightColor(D3DXVECTOR4(1, 1, 1, 0));
	Light::SetLightAmbientColor(D3DXVECTOR4(0.1f, 0, 0.5, 0));
}
