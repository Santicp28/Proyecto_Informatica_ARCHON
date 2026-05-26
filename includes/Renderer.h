#pragma once
#include <windows.h>
#include "ETSIDI.h"
#include "freeglut.h"
#include "Vector2D.h"

struct Color
{
	float r{ 1.0f }, g{ 1.0f }, b{ 1.0f };

};
class Renderer
{
	Vector2D sizeDibujo{};
public:
	void inicializa2D(unsigned int longitud, unsigned int altura);

	Vector2D obtenerSizeDibujo()const { return sizeDibujo; }

	void limpiarPantalla() { glClear(GL_COLOR_BUFFER_BIT); }//Primero dibuja en memoria (buffer), luego se muestra todo junto. Esto la borra
	void iniciaFrame() { glMatrixMode(GL_MODELVIEW); glLoadIdentity(); }

	void dibujaColorFondo(Color color)const {glClearColor(color.r, color.g, color.b, 1.0f);}

	void dibujaCuadrado(const Vector2D& centro, const Color& color, const Vector2D& size )const;
	void dibujaContornoCuadrado(const Vector2D& centro,const Color& color, const Vector2D& size)const;
	void dibujaLinea(const Vector2D& limite1, const Vector2D& limite2, const Color& color)const;
	void cuadradoParaPruebas()const;
	void dibujaSprite(const char* rutaPNG, const Vector2D& centro, double ancho, double alto) const;
	void dibujaTexto(const char* texto, const Vector2D& pos, double r = 1.0, double g = 1.0, double b = 1.0, int size = 12) const;

private:
	void dibujaColor(const Color& color)const { glColor3f(color.r, color.g, color.b); }
	
};