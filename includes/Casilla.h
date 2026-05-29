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
			&clara.sprite,
			&bastante_clara.sprite,
			&ligeramente_clara.sprite,
			&ligeramente_oscura.sprite,
			&bastante_oscura.sprite,
			&oscura.sprite,
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
