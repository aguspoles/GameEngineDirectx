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
	for each(MeshRenderer* entitie in _tiles)
	{
		if (entitie)
			delete entitie;
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
			float posX = _tileWidth * indiceColumna;
			float posY = _tileHeight * indiceFila;
			auto transform = _tiles[celda]->GetComponent<Transform>();
			transform->TranslateMesh(D3DXVECTOR3(posX, -posY, 6));
			_tiles[celda]->Render();
		}
	}
}

void TileMap::AddTile(MeshRenderer * entity)
{
	_tiles.push_back(entity);
}
