#include "stdafx.h"
#include "Tile.h"


Tile::Tile()
{
	_fila = 0;
	_columna = 0;
}

Tile::Tile(int fila, int columna)
{
	_fila = fila;
	_columna = columna;
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

void Tile::Init()
{
}

void Tile::UpdateComposite()
{
}

std::string Tile::GetType() const
{
	return std::string();
}
