#pragma once
#include"Vector2D.h"
#include"Renderer.h"
#include "Tipos.h"
#include "Graftablero.h"

class Casilla
{	
	TipoCasilla tipo;
	PosicionMatriz posicionMatriz;
	Color color;
	
	bool esOscilante = false;
	bool resaltada = false;


	const ETSIDI::Sprite* variantes[7] = {
			&azul.sprite,
			&turquesa.sprite,
			&verde.sprite,
			&amarilla.sprite,
			&naranja.sprite,
			&roja.sprite,
			&casillaespecial.sprite
	};

public:
	void inicializa(const TipoCasilla& nuevoTipo, PosicionMatriz nuevaPosicion);
	void dibuja(const Renderer& renderer, const Vector2D& posicion, double longitud)const;
	void setResaltada(bool estado) { resaltada = estado; }
	void cambiarOscilantes(bool ciclo);


	PosicionMatriz getPosicionMatriz() const { return posicionMatriz; }
	TipoCasilla getTipo() const { return tipo; }
};
