#include "Cursor.h"


void Cursor::mover(int df, int dc)
{
	posicion = { posicion.fila + df, posicion.columna + dc };
}

void Cursor::dibuja(const Renderer& renderer, const Vector2D& esquinaSuperiorIzda, double longitudCasilla, Bando b) const {

	Vector2D centro{
		esquinaSuperiorIzda.x + (posicion.columna + 0.5) * longitudCasilla,
		esquinaSuperiorIzda.y + (posicion.fila + 0.5) * longitudCasilla
	};

	if (b == Bando::AZUL) renderer.dibujaSprite(cursor_AZUL.sprite, centro, longitudCasilla, longitudCasilla);
	else if (b == Bando::ROJO) renderer.dibujaSprite(cursor_ROJO.sprite, centro, longitudCasilla, longitudCasilla);
}