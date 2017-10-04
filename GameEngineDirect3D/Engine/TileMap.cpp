#include "stdafx.h"
#include "TileMap.h"


TileMap::TileMap()
{
}

TileMap::TileMap(std::vector<std::vector<int>> tilemap, float tileWidth, float tileHeight)
{
	_tileMap = tilemap;
	_tileWidth = tileWidth;
	_tileHeight = tileHeight;
}


TileMap::~TileMap()
{
	for each(Tile* tile in _tiles)
	{
		if (tile)
			delete tile;
	}
}

void TileMap::Draw()
{
	//Recorremos cada fila del tilemap
	for (int indiceFila = 0; indiceFila < _tileMap.size(); indiceFila++)
	{
		std::vector<int>* fila = &_tileMap[indiceFila];

		//Recorremos cada columna del tilemap
		for (int indiceColumna = 0; indiceColumna < fila->size(); indiceColumna++)
		{
			int celda = fila->at(indiceColumna);
			float posX = _tileWidth * indiceColumna * 2;
			float posY = _tileHeight * indiceFila * 2;
			auto transform = _tiles[celda]->GetComponent<Transform>();
			transform->ScaleMesh(D3DXVECTOR3(_tileWidth, _tileHeight, 1));
			transform->TranslateMesh(D3DXVECTOR3(posX, -posY, 6));
			_tiles[celda]->Render();
		}
	}
}

void TileMap::AddTile(Tile * tile)
{
	_tiles.push_back(tile);
}
