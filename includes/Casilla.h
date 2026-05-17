#pragma once
#include"Vector2D.h"

enum class TipoCasilla {
	OSCURA,
	CLARA,
	OSCILANTE,
	PODER,
	INVALIDA
};

class Casilla
{

	friend class Interaccion;
	
	const double longitud{ 1.0 };
	TipoCasilla tipo;
	Vector2D posicion{};
	PosicionMatriz posicion_matriz;

public:
	//Casilla(unsigned int f =1, char c = 'a', const int layaut[][] = {});
	void dibuja(const Vector2D posicionPrimera)const;
	void setTipo(TipoCasilla nuevoTipo){tipo = nuevoTipo;}
	void setPosicion(const Vector2D nuevaPosicion) { posicion = nuevaPosicion; }
	TipoCasilla getTipo() const { return tipo; }
};
