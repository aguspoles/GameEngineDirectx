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
	_countTiles %= _frames.size();

	_y = _frames[_countTiles].fila * _tileHeight;
	_x = _frames[_countTiles].columna * _tileWidth;
	_material->Offset(D3DXVECTOR2(_x / _texWidth, _y / _texHeight));
	_material->Tiling(D3DXVECTOR3(_tileWidth / _texWidth, _tileHeight / _texHeight, 1));
}

void Animation::SetSpeed(float fps)
{
	_fps = fps;
}

void Animation::AddFrame(frame frame)
{
	_frames.push_back(frame);
}

void Animation::SetFrames(vector<frame> frames)
{
	_frames.clear();
	for (size_t i = 0; i < frames.size(); i++)
	{
		_frames.push_back(frames[i]);
	}
}

void Animation::SetIdleFrame(frame frame)
{
	_y = frame.fila * _tileHeight;
	_x = frame.columna * _tileWidth;
	_material->Offset(D3DXVECTOR2(_x / _texWidth, _y / _texHeight));
	_material->Tiling(D3DXVECTOR3(_tileWidth / _texWidth, _tileHeight / _texHeight, 1));
}

std::string Animation::GetName()
{
	return _name;
}
