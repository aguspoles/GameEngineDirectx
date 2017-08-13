#include "stdafx.h"
#include "Animation.h"


Animation::Animation()
{
}

Animation::Animation(std::string name, Material* mat, float tileWidth, float tileHeight,
	float texWidth, float texHeight) :
	_name(name),
	_material(mat),
	_tileWidth(tileWidth),
	_tileHeight(tileHeight),
	_texWidth(texWidth),
    _texHeight(texHeight)
{
	_tiles = { Tile(1,1), Tile(1,2), Tile(1,3) };
}


Animation::~Animation()
{
}

void Animation::Play()
{
	size_t i = 0;
	while (i < _tiles.size() && Game::DeltaTime() * 24 >= 1)
	{
		_y = _tiles[i].GetFila() * _tileHeight;
		_x = _tiles[i].GetColumna() * _tileWidth;
		_material->Offset(D3DXVECTOR2(_tileWidth / _texWidth, _tileHeight / _texHeight));
		_material->Tiling(D3DXVECTOR3(_x / _texWidth, _y / _texHeight, 1));
		i++;
	}
}
