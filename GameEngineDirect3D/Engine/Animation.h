#ifndef ANIMATION_H
#define ANIMATION_H
#include <string>
#include <vector>
#include "Material.h"
#include "Tile.h"
#include "Component.h"
#include "Game.h"

struct frame {
	int fila, columna;
	frame(int f, int c) { fila = f; columna = c; }
};

class ENGINE_API Animation : public Component
{
private:
	Material* _material;
	std::string _name;
	std::vector<frame> _frames;
	float _tileWidth;
	float _tileHeight;
	float _x;
	float _y;
	float _texWidth;
	float _texHeight;

	//variables for Play()
	float _total;
	float _fps;
	size_t _countTiles;
public:
	Animation();
	Animation(std::string name, Material* mat, float tileWidth, float tileHeight,
		float texWidth, float texHeight);
	~Animation();

	void Play();
	void SetSpeed(float fps);
	void AddFrame(frame frame);
	void SetFrames(vector<frame> frames);
	void SetIdleFrame(frame frame);
	std::string GetName();
};

#endif

