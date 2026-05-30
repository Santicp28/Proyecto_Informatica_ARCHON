#pragma once
#include "Tipos.h"
#include "Renderer.h"


class Cursor {
	PosicionMatriz posicion;

public:
	Cursor(PosicionMatriz p) : posicion(p) {}

	//comprueba si se puede mover y luego asigna la nueva posicion al cursor, se llama desde juego cuando se pulsa una flecha
	void mover(int df, int dc);
	void setPosicion(PosicionMatriz nuevaPosicion) { posicion = nuevaPosicion; }

	void dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& esquinaSuperiorIzda, double longitudCasilla, Bando b) const;

	PosicionMatriz getPosicion() const { return posicion; }


	
};