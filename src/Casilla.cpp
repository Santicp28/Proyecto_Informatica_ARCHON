#include "Casilla.h"

#include <cstdlib> 


void Casilla::inicializa(const TipoCasilla& nuevoTipo, PosicionMatriz nuevaPosicion)
{
    tipo = nuevoTipo;
    posicionMatriz = nuevaPosicion;

    switch (tipo)
    {
    case TipoCasilla::ROJA:
        color = { 0.f, 0.f, 0.f };
        break;

    case TipoCasilla::AZUL:
        color = { 1.f, 1.f, 1.f };
        break;
    case TipoCasilla::OSCILANTE: //empieza blanca
        //color = { 0.7f, 0.7f, 0.7f };
		esOscilante = true;
		tipo = TipoCasilla::AZUL;
        color = { 1.f, 1.f, 1.f };
        break;
    case TipoCasilla::PODER:
        color = { 1.f, 1.f, 0.f };
        break;
    }
}

void Casilla::dibuja(const Renderer& renderer, const Vector2D& posicion, double longitud) const
{
    //renderer.dibujaCuadrado(posicion, color, { longitud,longitud });
    //renderer.dibujaContornoCuadrado(posicion, { 0.5f, 0.5f, 0.5f }, { longitud,longitud });
    double escalaPieza = 1.3;


    if (tipo == TipoCasilla::AZUL) renderer.dibujaSprite(*variantes[0], posicion, longitud * escalaPieza, longitud * escalaPieza);
    else if (tipo == TipoCasilla::TURQUESA) renderer.dibujaSprite(*variantes[1], posicion, longitud * escalaPieza, longitud * escalaPieza);
    else if (tipo == TipoCasilla::VERDE) renderer.dibujaSprite(*variantes[2], posicion, longitud * escalaPieza, longitud * escalaPieza);
    else if (tipo == TipoCasilla::AMARILLA) renderer.dibujaSprite(*variantes[3], posicion, longitud * escalaPieza, longitud * escalaPieza);
    else if (tipo == TipoCasilla::NARANJA) renderer.dibujaSprite(*variantes[4], posicion, longitud * escalaPieza, longitud * escalaPieza);
    else if (tipo == TipoCasilla::ROJA) renderer.dibujaSprite(*variantes[5], posicion, longitud * escalaPieza, longitud * escalaPieza);
	else if (tipo == TipoCasilla::PODER) renderer.dibujaSprite(*variantes[6], posicion, longitud * escalaPieza, longitud * escalaPieza);
    
    if (resaltada) {
        renderer.dibujaSprite(posiciones.sprite, posicion, longitud, longitud);
    }

    
}


void Casilla::cambiarOscilantes(bool ciclo) {
    if (esOscilante) {
        if (ciclo) {
            if (tipo == TipoCasilla::AZUL) tipo = TipoCasilla::TURQUESA;
            else if (tipo == TipoCasilla::TURQUESA) tipo = TipoCasilla::VERDE;
            else if (tipo == TipoCasilla::VERDE) tipo = TipoCasilla::AMARILLA;
            else if (tipo == TipoCasilla::AMARILLA) tipo = TipoCasilla::NARANJA;
            else if (tipo == TipoCasilla::NARANJA)tipo = TipoCasilla::ROJA;
        }
        else {
            if (tipo == TipoCasilla::ROJA) tipo = TipoCasilla::NARANJA;
            else if (tipo == TipoCasilla::NARANJA) tipo = TipoCasilla::AMARILLA;
            else if (tipo == TipoCasilla::AMARILLA) tipo = TipoCasilla::VERDE;
            else if (tipo == TipoCasilla::VERDE) tipo = TipoCasilla::TURQUESA;
            else if (tipo == TipoCasilla::TURQUESA) tipo = TipoCasilla::AZUL;
        }
    }
}


