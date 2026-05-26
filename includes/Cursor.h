#pragma once
#include "Tipos.h"
#include "Interaccion.h"

class Cursor {
	PosicionMatriz posicion;

public:
	Cursor() : posicion{ 0, 0 } {}

	//comprueba si se puede mover y luego asigna la nueva posicion al cursor, se llama desde juego cuando se pulsa una flecha
	void mover(int df, int dc);
	void setPosicion(PosicionMatriz nuevaPosicion) { posicion = nuevaPosicion; }

	void dibuja(const Renderer& renderer, const Vector2D& esquinaSuperiorIzda, double longitudCasilla) const;

	PosicionMatriz getPosicion() const { return posicion; }


	
};