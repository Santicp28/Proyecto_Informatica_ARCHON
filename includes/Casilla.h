#pragma once
#include"Vector2D.h"
#include"Renderer.h"
#include "Tipos.h"

class Casilla
{	
	TipoCasilla tipo;
	PosicionMatriz posicionMatriz;
	Color color;
	
	bool esOscilante = false;
	bool resaltada = false;

public:
	void inicializa(const TipoCasilla& nuevoTipo, PosicionMatriz nuevaPosicion);
	void dibuja(const Renderer& renderer, const Vector2D& posicion, double longitud)const;
	void setResaltada(bool estado) { resaltada = estado; }
	void cambiarOscilantes(int cicloLuz_A_Oscuridad);


	PosicionMatriz getPosicionMatriz() const { return posicionMatriz; }
	TipoCasilla getTipo() const { return tipo; }
};
