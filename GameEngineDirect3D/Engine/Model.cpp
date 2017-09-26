#include "stdafx.h"
#include "Model.h"

Model::Model() : _vb(NULL), _ib(NULL), _primitivesCount(0)
{
}

Model::~Model()
{
	_vb->Release();
	_ib->Release();
}

Model::Model(const std::vector<Vertex> &vertexes,
	const std::vector<WORD> &indexes)
{
	ChargeModel(vertexes, indexes);
}

LPDIRECT3DVERTEXBUFFER9 Model::GetVertexBuffer()
{
	return _vb;
}

LPDIRECT3DINDEXBUFFER9 Model::GetIndexBuffer()
{
	return _ib;
}

std::vector<Vertex> Model::GetVertexes()
{
	return _vertexes;
}

std::vector<WORD> Model::GetIndexes()
{
	return _indexes;
}

UINT Model::GetPrimitivesCount()
{
	return _primitivesCount;
}

void Model::LoadModelFromFile(const char* fileName)
{
	std::vector<D3DXVECTOR3> positions;
	std::vector<D3DXVECTOR3> normals;
	std::vector<D3DXVECTOR2> uvs;

	FILE* file;
	fopen_s(&file, fileName, "r");

	//feof nos indica si estamos en el fin del archivo
	while (file && !feof(file))
	{
		//Obtengo la primer palabra despues de donde estoy parado
		//y la guardo en el array de chars
		char lineHeader[128];
		fscanf(file, "%s", lineHeader);

		//Si la primer palabra es V nos encontramos con una posicion
		//del vertice y la guardamos
		if (strcmp(lineHeader, "v") == 0)
		{
			D3DXVECTOR3 position;
			fscanf(file, "%f %f %f\n", &position.x, &position.y, &position.z);
			positions.push_back(position);
		}
		else if (strcmp(lineHeader, "vt") == 0)
		{
			D3DXVECTOR2 uv;
			fscanf(file, "%f %f\n", &uv.x, &uv.y);
			uvs.push_back(uv);
		}
		else if (strcmp(lineHeader, "vn") == 0)
		{
			D3DXVECTOR3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			normals.push_back(normal);
		}
		else if (strcmp(lineHeader, "f") == 0)
		{
			Vertex vertex;
			int posIndex, uvIndex, normalIndex;

			fscanf(file, "%d/%d/%d ", &posIndex, &uvIndex, &normalIndex);
			vertex.x = positions[posIndex - 1].x;
			vertex.y = positions[posIndex - 1].y;
			vertex.z = positions[posIndex - 1].z;
			vertex.tu = uvs[uvIndex - 1].x;
			vertex.tv = uvs[uvIndex - 1].y;
			vertex.nx = normals[normalIndex - 1].x;
			vertex.ny = normals[normalIndex - 1].y;
			vertex.nz = normals[normalIndex - 1].z;
			_indexes.push_back(_vertexes.size());
			_vertexes.push_back(vertex);

			fscanf(file, "%d/%d/%d ", &posIndex, &uvIndex, &normalIndex);
			vertex.x = positions[posIndex - 1].x;
			vertex.y = positions[posIndex - 1].y;
			vertex.z = positions[posIndex - 1].z;
			vertex.tu = uvs[uvIndex - 1].x;
			vertex.tv = uvs[uvIndex - 1].y;
			vertex.nx = normals[normalIndex - 1].x;
			vertex.ny = normals[normalIndex - 1].y;
			vertex.nz = normals[normalIndex - 1].z;
			_indexes.push_back(_vertexes.size());
			_vertexes.push_back(vertex);

			fscanf(file, "%d/%d/%d\n", &posIndex, &uvIndex, &normalIndex);
			vertex.x = positions[posIndex - 1].x;
			vertex.y = positions[posIndex - 1].y;
			vertex.z = positions[posIndex - 1].z;
			vertex.tu = uvs[uvIndex - 1].x;
			vertex.tv = uvs[uvIndex - 1].y;
			vertex.nx = normals[normalIndex - 1].x;
			vertex.ny = normals[normalIndex - 1].y;
			vertex.nz = normals[normalIndex - 1].z;
			_indexes.push_back(_vertexes.size());
			_vertexes.push_back(vertex);
		}
	}

	ChargeModel(_vertexes, _indexes);
}

void Model::ChargeModel(const std::vector<Vertex> &vertexes,
	const std::vector<WORD> &indexes)
{
	GameSetUp::Device->CreateVertexBuffer(vertexes.size() * sizeof(Vertex),
		D3DUSAGE_WRITEONLY,//el uso q le vamos a dar
		CUSTOMFVF,
		D3DPOOL_MANAGED,//lo subimos a vram
		&_vb,
		NULL);
	//puntero a la memoria del vb en la vram
	VOID *data;
	//compiamos el array de veritces q esta en la ram de la cpu 
	//a el puntero del vb en la vram, especificando cuantos 
	//bytes vamos a copiar
	_vb->Lock(0, 0, &data, 0);
	memcpy(data, &vertexes[0], vertexes.size() * sizeof(Vertex));
	_vb->Unlock();

	if (&indexes)
	{
		GameSetUp::Device->CreateIndexBuffer(
			indexes.size() * sizeof(WORD),
			D3DUSAGE_WRITEONLY,
			D3DFMT_INDEX16,
			D3DPOOL_MANAGED,
			&_ib,
			NULL
		);
		VOID *indexData;
		_ib->Lock(0, 0, &indexData, 0);
		memcpy(indexData, &indexes[0], indexes.size() * sizeof(WORD));
		_ib->Unlock();
	}

	_primitivesCount = indexes.size() / 3;//triangulos (3 vertices)
}
