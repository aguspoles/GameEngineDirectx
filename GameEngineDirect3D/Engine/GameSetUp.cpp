#include "stdafx.h"
#include "GameSetUp.h"
#include "Input.h"

LPDIRECT3DDEVICE9 GameSetUp::Device = NULL;
//Camera* GameSetUp::_camera = NULL;

GameSetUp::GameSetUp() 
{
	//_camera = new Camera();
}


GameSetUp::~GameSetUp()
{
	/*if (_camera)
	{
		delete _camera;
		_camera = NULL;
	}*/
}

//Camera * GameSetUp::GetCamera()
//{
//	return _camera;
//}

