#pragma once
#include <map>
#include<vector>

class Input
{
private:
	std::map<std::string, std::vector<int>*> _inputMap;
	byte _keys[256];
	byte _prevKeys[256];
	LPDIRECTINPUTDEVICE8 _KeyDev;

public:
	Input();
	Input(_In_ HINSTANCE hInstance, HWND hWnd);
	~Input();

	void CheckInput();
	bool KeyPressed(const std::string& action);
	bool KeyJustPressed(const std::string& action);
	bool KeyReleased(const std::string& action);
};

