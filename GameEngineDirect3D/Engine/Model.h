#pragma once
#include "stdafx.h"
#include "Game.h"
#include <vector>

#define CUSTOMFVF (D3DFVF_XYZ | D3DFVF_DIFFUSE)

struct Vertex
{
	FLOAT x, y, z;
	DWORD color;
};

class Model
{
private:
	LPDIRECT3DVERTEXBUFFER9 _vb;
	LPDIRECT3DINDEXBUFFER9 _ib;
	std::vector<Vertex> _vertexes;
	std::vector<WORD> _indexes;
public:
	Model();
	Model(LPDIRECT3DDEVICE9 dev, const std::vector<Vertex> &vertexes, const std::vector<WORD> &indexes);
	~Model();

	LPDIRECT3DVERTEXBUFFER9 GetVertexBuffer();
	LPDIRECT3DINDEXBUFFER9 GetIndexBuffer();
	std::vector<Vertex>& GetVertexes();
	std::vector<WORD>& GetIndexes();

};

