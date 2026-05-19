#pragma once
#include"Vector2D.h"
#include"PosicionMatriz.h"
#include"DesacopleGrafico.h"

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
	
	TipoCasilla tipo;
	PosicionMatriz posicionMatriz;
	Color color;

public:
	void dibuja(const Vector2D& posicion, double longitud)const;
	void setTipo(const TipoCasilla& nuevoTipo);
	void setPosicion(const Vector2D& posicionPrimera, const unsigned int f, const unsigned int c);
	void inicializa(const TipoCasilla& nuevoTipo, PosicionMatriz nuevaPosicion);
};
