#include "Cursor.h"


void Cursor::mover(int df, int dc)
{
	PosicionMatriz nuevaPosicion{ posicion.fila + df, posicion.columna + dc };

	if (Interaccion::posicionValida(nuevaPosicion)) posicion = nuevaPosicion;
}

void Cursor::dibuja(const Renderer& renderer, const Vector2D& esquinaSuperiorIzda, double longitudCasilla) const {

	Vector2D centro{
		esquinaSuperiorIzda.x + (posicion.columna + 0.5) * longitudCasilla,
		esquinaSuperiorIzda.y + (posicion.fila + 0.5) * longitudCasilla
	};


	renderer.dibujaSprite("bin/Graficos/cursor.PNG", centro, longitudCasilla, longitudCasilla);
}