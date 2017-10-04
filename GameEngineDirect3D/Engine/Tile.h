#ifndef TILE_H
#define TILE_H
#include "MeshRenderer.h"

class ENGINE_API Tile : public MeshRenderer
{
private:
	float _fila;
	float _columna;
public:
	Tile();
	Tile(int fila, int columna);
	~Tile();

	int GetFila();
	int GetColumna();
	virtual void Init() override;
	virtual void UpdateComposite() override;
	virtual std::string GetType() const;
};
#endif

