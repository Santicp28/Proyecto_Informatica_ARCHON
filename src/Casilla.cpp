#include "Casilla.h"
#include "DesacopleGrafico.h"

void Casilla::dibuja(const Vector2D& posicion, double longitud) const
{
	DesacopleGrafico::dibujaCuadrado(posicion, color, longitud);
    DesacopleGrafico::dibujaContornoCuadrado(posicion, { 0.5f, 0.5f, 0.5f }, longitud);
}

void Casilla::inicializa(const TipoCasilla& nuevoTipo, PosicionMatriz nuevaPosicion)
{
    tipo = nuevoTipo;
    posicionMatriz = nuevaPosicion;
    switch (tipo)
    {
    case TipoCasilla::OSCURA:
        color = { 0.f, 0.f, 0.f };
        break;

    case TipoCasilla::CLARA:
        color = { 1.f, 1.f, 1.f };
        break;
    case TipoCasilla::OSCILANTE: //empieza blanca
        color = { 0.8f, 0.8f, 0.8f };
        break;
    case TipoCasilla::PODER:
        color = { 1.f, 1.f, 0.f };
        break;
    }
}
