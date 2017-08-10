#ifndef INPUT_H
#define INPUT_H
#include <map>
#include<vector>

class ENGINE_API Input
{
private:
	static Input* _instance;
	static std::map<std::string, std::vector<int>*> _inputMap;
	static byte _keys[256];
	static byte _prevKeys[256];
	static LPDIRECTINPUTDEVICE8 _KeyDev;

public:
	static Input* Instance(_In_ HINSTANCE hInstance, HWND hWnd);
	~Input();
	static void CheckInput();
	static bool KeyPressed(const std::string action);
	static bool KeyJustPressed(const std::string action);
	static bool KeyReleased(const std::string action);

protected:
	Input();
	Input(_In_ HINSTANCE hInstance, HWND hWnd);

};

#endif