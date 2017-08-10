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
	Player* p = new Player(dev);
	Enemy* e = new Enemy(dev);
	PickUp* pick = new PickUp(dev);
	AddEntitie(e);
	AddEntitie(p);
	AddEntitie(pick);

	_camera->GetViewMatrix(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0));
	_camera->SetPerspective(60, (float)640 / 480, 0.1f, 100.0f);
	_camera->SetRenderView(dev);
}