#ifndef TILE_H
#define TILE_H

class ENGINE_API Tile
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
};
#endif

