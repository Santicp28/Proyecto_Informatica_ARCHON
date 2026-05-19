#include "DesacopleGrafico.h"

void DesacopleGrafico::dibujaContornoCuadrado(const Vector2D& centro, const double longitud)
{
	// 2. Dibujar el borde con un pequeño offset en Z para evitar parpadeo
	glColor3f(1.0f, 0.0f, 0.0f); // Gris oscuro para bordes elegantes
	glLineWidth(2.0f);
	glBegin(GL_LINE_LOOP);
	glVertex3f(x, y, 0.01f);
	glVertex3f(x + sizeCasillas, y, 0.01f);
	glVertex3f(x + sizeCasillas, y + sizeCasillas, 0.01f);
	glVertex3f(x, y + sizeCasillas, 0.01f);
	glEnd();
}
void DesacopleGrafico::dibujaCuadrado(const Vector2D& centro, double longitud)
{
	longitud = longitud / 2.0;
	glBegin(GL_QUADS);

	glVertex2d(centro.x - longitud, centro.y - longitud); // abajo izquierda
	glVertex2d(centro.x + longitud, centro.y - longitud); // abajo derecha
	glVertex2d(centro.x + longitud, centro.y + longitud); // arriba derecha
	glVertex2d(centro.x - longitud, centro.y + longitud); // arriba izquierda

	glEnd();

}