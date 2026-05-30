#include "Cursor.h"


void Cursor::mover(int df, int dc)
{
	posicion = { posicion.fila + df, posicion.columna + dc };
}

void Cursor::dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& esquinaSuperiorIzda, double longitudCasilla, Bando b) const {

	Vector2D centro{
		esquinaSuperiorIzda.x + (posicion.columna + 0.5) * longitudCasilla,
		esquinaSuperiorIzda.y + (posicion.fila + 0.5) * longitudCasilla
	};

	if (b == Bando::LUZ) renderer.dibujaContornoCuadrado(contenedorSprites.spriteCursorLuz, centro,Config::amarillo, {longitudCasilla, longitudCasilla});
	else if (b == Bando::OSCURIDAD) renderer.dibujaContornoCuadrado(contenedorSprites.spriteCursorOscuro, centro, Config::morado, {longitudCasilla, longitudCasilla});
}