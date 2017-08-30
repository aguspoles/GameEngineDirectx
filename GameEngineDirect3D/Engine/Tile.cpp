#include "stdafx.h"
#include "Tile.h"


Tile::Tile()
{
	_fila = 1;
	_columna = 1;
}

Tile::Tile(int fila, int columna)
{
	_fila = fila-1;
	_columna = columna-1;
}


Tile::~Tile()
{
}

int Tile::GetFila()
{
	return _fila;
}

int Tile::GetColumna()
{
	return _columna;
}
