#ifndef MODEL_H
#define MODEL_H
#include "GameSetUp.h"
#include <vector>

#define CUSTOMFVF (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1)

struct Vertex
{
	FLOAT x, y, z;
	FLOAT nx, ny, nz;
	FLOAT tu, tv;
};

class ENGINE_API Model
{
private:
	LPDIRECT3DVERTEXBUFFER9 _vb;
	LPDIRECT3DINDEXBUFFER9 _ib;
	std::vector<Vertex> _vertexes;
	std::vector<WORD> _indexes;
	UINT _primitivesCount;
public:
	Model();
	Model(const std::vector<Vertex> &vertexes,
		const std::vector<WORD> &indexes);
	~Model();

	LPDIRECT3DVERTEXBUFFER9 GetVertexBuffer();
	LPDIRECT3DINDEXBUFFER9 GetIndexBuffer();
	std::vector<Vertex> GetVertexes();
	std::vector<WORD> GetIndexes();
	UINT GetPrimitivesCount();
	void LoadModelFromFile(const char* file);
	void ChargeModel(const std::vector<Vertex> &vertexes,
		const std::vector<WORD> &indexes);

};

#endif

