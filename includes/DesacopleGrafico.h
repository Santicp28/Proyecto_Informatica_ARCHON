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
	static void dibujaColor(Color color) { glColor3f(color.r, color.g, color.b); }
	static void dibujaColorFondo(Color color) { glClearColor(color.r, color.g, color.b, 1.0f); }
	static void desactivarSombras(){ glDisable(GL_LIGHTING); } // Desactivar luces para el tablero
	static void setCamara(const Vector2D& centro,double camaraZ) {gluLookAt(centro.x, centro.y, camaraZ,// posición de la cámara
																			centro.x, centro.y, 0.0,    // punto al que mira
																			 0.0, 1.0, 0.0);}; // vector "arriba"(contrario a gravedad)

	static void dibujaCuadrado(const Vector2D& centro, const Color& color, double longitud);
	static void dibujaContornoCuadrado(const Vector2D& centro,const Color& color, double longitud);
	
};