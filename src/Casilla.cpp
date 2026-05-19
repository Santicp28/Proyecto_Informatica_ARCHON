#include "Casilla.h"
#include "DesacopleGrafico.h"

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
        color = { 0.7f, 0.7f, 0.7f };
        break;
    case TipoCasilla::PODER:
        color = { 1.f, 1.f, 0.f };
        break;
    }
}

void Casilla::dibuja(const Vector2D& posicion, double longitud) const
{
    DesacopleGrafico::dibujaCuadrado(posicion, color, longitud);
    DesacopleGrafico::dibujaContornoCuadrado(posicion, { 0.5f, 0.5f, 0.5f }, longitud);
}

void Casilla::setTipo(const TipoCasilla& nuevoTipo)
{
	tipo = nuevoTipo;
    switch (tipo)
    {
    case TipoCasilla::OSCURA:
        DesacopleGrafico::setColor({ 0.f, 0.f, 0.f });
            break;

    case TipoCasilla::CLARA: 
        DesacopleGrafico::setColor({ 1.f, 1.f, 1.f });
            break;
    case TipoCasilla::OSCILANTE:
        DesacopleGrafico::setColor({ 1.f, 1.f, 1.f });
            break;
    case TipoCasilla::PODER:
        DesacopleGrafico::setColor({ 1.f, 1.f, 0.f });
            break;
    }
}

