#pragma once
#include "freeglut.h"
#include "Vector2D.h"
struct Color
{
	unsigned char r{ 255 }, g{ 255 }, b{ 255 };
};
struct DesacopleGrafico
{
	void glLimpiarPantalla()const { glClear(GL_COLOR_BUFFER_BIT); }
	void glPonCuadrado(const Vector2D& centro, const double& longitud)const;
	void glPonColor(Color color) const{glColor3ub(color.r, color.g, color.b);}
	
};
inline void DesacopleGrafico::glPonCuadrado(const Vector2D& centro, const double& longitud)const
{
	double mitad{ longitud / 2.0 };
	glBegin(GL_QUADS);

	glVertex2d(centro.x-mitad, centro.y-mitad); // abajo izquierda
	glVertex2d(centro.x+ mitad, centro.y- mitad); // abajo derecha
	glVertex2d(centro.x+ mitad, centro.y+ mitad); // arriba derecha
	glVertex2d(centro.x- mitad, centro.y+ mitad); // arriba izquierda

	glEnd();

}