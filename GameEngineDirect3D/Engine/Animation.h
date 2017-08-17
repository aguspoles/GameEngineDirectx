#pragma once
#include <string>
#include <vector>
#include "Game.h"
#include "Material.h"
#include "Tile.h"

class ENGINE_API Animation
{
private:
	Material* _material;
	std::string _name;
	std::vector<Tile> _tiles;
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
	std::string GetName();
};

