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
    _texHeight(texHeight),
	_countTiles(0),
	_total(0)
{
	_tiles = { 
		Tile(1,1), Tile(1,2), Tile(1,3), Tile(1,4), Tile(1,5), Tile(1,6),
		Tile(2,1), Tile(2,2), Tile(2,3), Tile(2,4),Tile(2,5), Tile(2,6),
		Tile(3,1), Tile(3,2), Tile(3,3), Tile(3,4),Tile(3,5), Tile(3,6),
		Tile(4,1), Tile(4,2), Tile(4,3), Tile(4,4),Tile(4,5), Tile(4,6),
		Tile(5,1), Tile(5,2), Tile(5,3), Tile(5,4),Tile(5,5), Tile(5,6) };

	_y = _tiles[0].GetFila() * _tileHeight;
	_x = _tiles[0].GetColumna() * _tileWidth;
	mat->Offset(D3DXVECTOR2(_x / _texWidth, _y / _texHeight));
	mat->Tiling(D3DXVECTOR3(_tileWidth / _texWidth, _tileHeight / _texHeight, 1));
}


Animation::~Animation()
{
}

void Animation::Play()
{
	_total += Game::DeltaTime();
	while (_total >= _fps)
	{
		_total -= _fps;
		_countTiles++;
	}
	_countTiles %= _tiles.size();

	_y = _tiles[_countTiles].GetFila() * _tileHeight;
	_x = _tiles[_countTiles].GetColumna() * _tileWidth;
	_material->Offset(D3DXVECTOR2(_x / _texWidth, _y / _texHeight));
	_material->Tiling(D3DXVECTOR3(_tileWidth / _texWidth, _tileHeight / _texHeight, 1));
}

void Animation::SetSpeed(float fps)
{
	_fps = fps;
}

std::string Animation::GetName()
{
	return _name;
}
