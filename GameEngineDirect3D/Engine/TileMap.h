#ifndef TILEMAP_H
#define TILEMAP_H
#include <vector>
#include "Entity.h"

class ENGINE_API TileMap 
{
private:
	std::vector<std::vector<int>> _tileMap;
	std::vector<Entity*> _tiles;
	float _tileWidth;
	float _tileHeight;
public:
	TileMap();
	TileMap(std::vector<std::vector<int>> tilemap, float tileWidth, float tileHeight);
	~TileMap();

	void Draw();
	void AddTile(Entity* entity);
};
#endif
