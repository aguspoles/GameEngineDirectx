//#pragma once
#ifndef MODEL_H
#define MODEL_H
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
	UINT _primitivesCount;
public:
	Model();
	Model(LPDIRECT3DDEVICE9 dev, const std::vector<Vertex> &vertexes,
		const std::vector<WORD> &indexes, UINT primCount);
	~Model();

	LPDIRECT3DVERTEXBUFFER9 GetVertexBuffer();
	LPDIRECT3DINDEXBUFFER9 GetIndexBuffer();
	std::vector<Vertex> GetVertexes();
	std::vector<WORD> GetIndexes();
	UINT GetPrimitivesCount();

};

#endif

