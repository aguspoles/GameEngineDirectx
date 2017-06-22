#ifndef INPUT_H
#define INPUT_H
#include <map>
#include<vector>

enum ACTION{MOVE_LEFT, MOVE_RIGHT, MOVE_FORWARD};

class ENGINE_API Input
{
private:
	std::map<ACTION, std::vector<int>*> _inputMap;
	byte _keys[256];
	byte _prevKeys[256];
	LPDIRECTINPUTDEVICE8 _KeyDev;

public:
	Input();
	Input(_In_ HINSTANCE hInstance, HWND hWnd);
	~Input();

	void CheckInput();
	bool KeyPressed(const ACTION& action);
	bool KeyJustPressed(const ACTION& action);
	bool KeyReleased(const ACTION& action);
};

#endif