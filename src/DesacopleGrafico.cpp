#include "DesacopleGrafico.h"

void DesacopleGrafico::dibujaCuadrado(const Vector2D& centro, const Color& color, double longitud)
{
	longitud = longitud / 2.0;
	DesacopleGrafico::dibujaColor(color);
	glBegin(GL_QUADS);

	glVertex2d(centro.x - longitud, centro.y - longitud); // abajo izquierda
	glVertex2d(centro.x + longitud, centro.y - longitud); // abajo derecha
	glVertex2d(centro.x + longitud, centro.y + longitud); // arriba derecha
	glVertex2d(centro.x - longitud, centro.y + longitud); // arriba izquierda

	glEnd();

}

void DesacopleGrafico::dibujaContornoCuadrado(const Vector2D& centro, const Color& color, double longitud)
{
	// 2. Dibujar el borde con un pequeño offset en Z para evitar parpadeo
	longitud = longitud / 2.0;
	DesacopleGrafico::dibujaColor(color);
	glLineWidth(2.0f);//ancho de lineas
	glBegin(GL_LINE_LOOP);
	glVertex3d(centro.x - longitud, centro.y - longitud, 0.1); // abajo izquierda
	glVertex3d(centro.x + longitud, centro.y - longitud, 0.1); // abajo derecha
	glVertex3d(centro.x + longitud, centro.y + longitud, 0.1); // arriba derecha
	glVertex3d(centro.x - longitud, centro.y + longitud, 0.1); // arriba izquierda
	glEnd();
}
