#pragma once
#include "freeglut.h"
#include "Vector2D.h"
struct Color
{
	float r{ 1.0f }, g{ 1.0f }, b{ 1.0f };

};
struct DesacopleGrafico
{
	static void limpiarPantalla() { glClear(GL_COLOR_BUFFER_BIT); }
	static void dibujaCuadrado(const Vector2D& centro, const double longitud);
	static void setColor(Color color) { glColor3f(color.r, color.g, color.b); }
	static void setColorFondo(Color color) { glClearColor(color.r, color.g, color.b, 1.0f); }
	static void desactivarSombras(){ glDisable(GL_LIGHTING); } // Desactivar luces para el tablero
	static void dibujaContornoCuadrado(const Vector2D& centro, const double longitud);
	
};
