#pragma once
#include"Vector2D.h"
#include "Tipos.h"

class Casilla
{
	friend class Interaccion;
	
	const double longitud{ 1.0 };
	TipoCasilla tipo;
	Vector2D posicion2D{};
	PosicionMatriz posicionMatriz;

public:
	//Casilla(unsigned int f =1, char c = 'a', const int layaut[][] = {});
	void dibuja()const;
	void setTipo(const TipoCasilla& nuevoTipo);
	void setPosicion(const Vector2D& posicionPrimera, const unsigned int f, const unsigned int c);
	PosicionMatriz getPosicionMatriz() const { return posicionMatriz; }
	TipoCasilla getTipo() const { return tipo; }
};
