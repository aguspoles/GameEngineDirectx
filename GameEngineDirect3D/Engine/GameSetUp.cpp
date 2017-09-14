#include "stdafx.h"
#include "GameSetUp.h"
#include "Input.h"

LPDIRECT3DDEVICE9 GameSetUp::Device = NULL;
Camera* GameSetUp::_camera = NULL;

GameSetUp::GameSetUp() 
{
}


GameSetUp::~GameSetUp()
{

}

Camera * GameSetUp::GetCamera()
{
	return _camera;
}

