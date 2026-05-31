#pragma once
#include "ETSIDI.h"
#include "freeglut.h"
#include "Vector2D.h"
#include "Config.h"
#include <string>
#include "Tipos.h"
#include"ContenedorSprites.h"

using ETSIDI::Sprite, std::unique_ptr;

class Renderer
{

public:
	void inicializa2D();

	void iniciaFrame() { glClear(GL_COLOR_BUFFER_BIT); glMatrixMode(GL_MODELVIEW); glLoadIdentity(); }//Primero dibuja en memoria (buffer), luego se muestra todo junto. Esto la borra

	void dibujaColorFondo(Color color)const {glClearColor(color.r, color.g, color.b, 1.0f);}

	void dibujaCuadrado(const unique_ptr<Sprite>& sprite, const Vector2D& centro, const Color& color, const Vector2D& size )const;
	void dibujaContornoCuadrado(const unique_ptr<Sprite>& sprite,const Vector2D& centro,const Color& color, const Vector2D& size)const;
	void dibujaLinea(const unique_ptr<Sprite>& sprite, const Vector2D& limite1, const Vector2D& limite2, const Color& color)const;
	void dibujaOvalo(const unique_ptr<Sprite>& sprite, const Vector2D& centro, const Color& color, double radioX, double radioY) const;
	void dibujaSpriteRotado(const unique_ptr<Sprite>& sprite, const Vector2D& base, Vector2D size, double angulo) const;

	void dibujaSprite(const unique_ptr<Sprite>& sprite, const Vector2D& centro, const Vector2D& size) const;
	void dibujaTexto(const std::string& texto, const Vector2D& pos, const Color& color, int size, AlineacionTexto alineacion) const;


private:
	void dibujaColor(const Color& color)const { glColor3f(color.r, color.g, color.b); }
	void empiezaUI() const;
	void terminaUI() const;
};