#pragma once
#include"Vector2D.h"
enum class TipoCasilla {
	OSCURA,
	CLARA,
	OSCILANTE,
	PODER,
	INVALIDA
};
struct Casilla
{
	unsigned int fila;
	unsigned int columna;
	const double longitud{ 1.0 };
	TipoCasilla tipo_;
	Vector2D posicionLocal_{};

	//Casilla(unsigned int f =1, char c = 'a', const int layaut[][] = {});
	void dibuja(const Vector2D posicionPrimera)const;
};
