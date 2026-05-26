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
public:
	void inicializa2D();

	void iniciaFrame() { glClear(GL_COLOR_BUFFER_BIT); glMatrixMode(GL_MODELVIEW); glLoadIdentity(); }//Primero dibuja en memoria (buffer), luego se muestra todo junto. Esto la borra

	void dibujaColorFondo(Color color)const {glClearColor(color.r, color.g, color.b, 1.0f);}

	void dibujaCuadrado(const Vector2D& centro, const Color& color, const Vector2D& size )const;
	void dibujaContornoCuadrado(const Vector2D& centro,const Color& color, const Vector2D& size)const;
	void dibujaLinea(const Vector2D& limite1, const Vector2D& limite2, const Color& color)const;
	void cuadradoParaPruebas()const;
	void dibujaOvalo(const Vector2D& centro, const Color& color, double radioX, double radioY) const;

private:
	void dibujaColor(const Color& color)const { glColor3f(color.r, color.g, color.b); }
	
};