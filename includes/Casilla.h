#pragma once
#include"Vector2D.h"
#include"Renderer.h"
#include "Tipos.h"

class Casilla
{
	friend class Interaccion;
	
	TipoCasilla tipo;
	PosicionMatriz posicionMatriz;
	Color color;

public:
	void inicializa(const TipoCasilla& nuevoTipo, PosicionMatriz nuevaPosicion);
	void dibuja(const Renderer& renderer, const Vector2D& posicion, double longitud)const;
	PosicionMatriz getPosicionMatriz() const { return posicionMatriz; }
	TipoCasilla getTipo() const { return tipo; }
};
