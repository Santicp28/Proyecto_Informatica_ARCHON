#pragma once
#include"Vector2D.h"
#include "Tipos.h"

class Casilla
{
	friend class Interaccion;
	
	TipoCasilla tipo;
	PosicionMatriz posicionMatriz;
	Color color;

public:
	void inicializa(const TipoCasilla& nuevoTipo, PosicionMatriz nuevaPosicion);
	void dibuja(const Vector2D& posicion, double longitud)const;
	PosicionMatriz getPosicionMatriz() const { return posicionMatriz; }
	TipoCasilla getTipo() const { return tipo; }
};
