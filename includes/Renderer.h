#pragma once
#include "freeglut.h"
#include "Vector2D.h"
#include "Config.h"
struct Color
{
	float r{ 1.0f }, g{ 1.0f }, b{ 1.0f };

};
class Renderer
{
	void inicializa2D();

	void limpiarPantalla() { glClear(GL_COLOR_BUFFER_BIT); }//Primero dibuja en memoria (buffer), luego se muestra todo junto. Esto la borra
	void iniciaFrame() { glMatrixMode(GL_MODELVIEW); glLoadIdentity(); }

	void dibujaColorFondo(Color color)const {glClearColor(color.r, color.g, color.b, 1.0f);}

	void dibujaCuadrado(const Vector2D& centro, const Color& color, const Vector2D& size )const;
	void dibujaContornoCuadrado(const Vector2D& centro,const Color& color, const Vector2D& size)const;

private:
	void dibujaColor(const Color& color)const { glColor3f(color.r, color.g, color.b); }
	
};