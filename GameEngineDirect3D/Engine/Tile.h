#pragma once

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

