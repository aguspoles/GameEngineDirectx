#include "stdafx.h"
#include "Input.h"


Input::Input()
{
}

Input::Input(_In_ HINSTANCE hInstance, HWND hWnd)
{
	LPDIRECTINPUT8 dip;
	DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&dip, NULL);
	dip->CreateDevice(GUID_SysKeyboard, &_KeyDev, NULL);
	_KeyDev->SetDataFormat(&c_dfDIKeyboard);
	_KeyDev->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	_KeyDev->Acquire();

	_inputMap[ACTION::MOVE_LEFT] = new std::vector<int>{ DIK_LEFTARROW, DIK_A };
	_inputMap[ACTION::MOVE_RIGHT] = new std::vector<int>{ DIK_RIGHTARROW, DIK_D };
	_inputMap[ACTION::MOVE_FORWARD] = new std::vector<int>{ DIK_UPARROW, DIK_W };
}


Input::~Input()
{
	for (std::map<ACTION, std::vector<int>*>::iterator it = _inputMap.begin(); 
		it != _inputMap.end(); it++)
	{
		delete it->second;
	}
}

void Input::CheckInput()
{
	for (size_t i = 0; i < 256; i++)
		_prevKeys[i] = _keys[i];

	_KeyDev->GetDeviceState(sizeof(_keys), &_keys);
}

bool Input::KeyPressed(const ACTION& action)
{
    std::vector<int>* getInput = _inputMap[action];
	for (size_t i = 0; i < getInput->size(); i++)
	{
		if (_keys[getInput->at(i)])
			return true;
	}
	return false;
}

bool Input::KeyJustPressed(const ACTION& action)
{
	std::vector<int>* getInput = _inputMap[action];
	for (size_t i = 0; i < getInput->size(); i++)
	{
		if (_keys[getInput->at(i)] && !_prevKeys[getInput->at(i)])
			return true;
	}
	return false;
}

bool Input::KeyReleased(const ACTION& action)
{
	std::vector<int>* getInput = _inputMap[action];
	for (size_t i = 0; i < getInput->size(); i++)
	{
		if (!_keys[getInput->at(i)] && _prevKeys[getInput->at(i)])
			return true;
	}
	return false;
}

