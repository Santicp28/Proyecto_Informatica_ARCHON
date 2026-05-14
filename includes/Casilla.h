#pragma once
#include"Vector2D.h"

struct Casilla
{
	unsigned int fila;
	unsigned int columna;
	double longitud;
	Vector2D posicionLocal_{};

	Casilla(unsigned int f =1, char c = 'a');
	void dibuja();
};
