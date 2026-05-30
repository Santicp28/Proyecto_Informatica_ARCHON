#include "Casilla.h"

#include <cstdlib> 


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
        //color = { 0.7f, 0.7f, 0.7f };
		esOscilante = true;
		tipo = TipoCasilla::CLARA;
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


    if (tipo == TipoCasilla::CLARA) renderer.dibujaSprite(*variantes[0], posicion, longitud * escalaPieza, longitud * escalaPieza);
    else if (tipo == TipoCasilla::BASTANTE_CLARA) renderer.dibujaSprite(*variantes[1], posicion, longitud * escalaPieza, longitud * escalaPieza);
    else if (tipo == TipoCasilla::LIGERAMENTE_CLARA) renderer.dibujaSprite(*variantes[2], posicion, longitud * escalaPieza, longitud * escalaPieza);
    else if (tipo == TipoCasilla::LIGERAMENTE_OSCURA) renderer.dibujaSprite(*variantes[3], posicion, longitud * escalaPieza, longitud * escalaPieza);
    else if (tipo == TipoCasilla::BASTANTE_OSCURA) renderer.dibujaSprite(*variantes[4], posicion, longitud * escalaPieza, longitud * escalaPieza);
    else if (tipo == TipoCasilla::OSCURA) renderer.dibujaSprite(*variantes[5], posicion, longitud * escalaPieza, longitud * escalaPieza);
	else if (tipo == TipoCasilla::PODER) renderer.dibujaSprite(*variantes[6], posicion, longitud * escalaPieza, longitud * escalaPieza);
    
    if (resaltada) {
        renderer.dibujaSprite(posiciones.sprite, posicion, longitud, longitud);
    }

    
}


void Casilla::cambiarOscilantes(bool ciclo) {
    if (esOscilante) {
        if (ciclo) {
            if (tipo == TipoCasilla::CLARA) tipo = TipoCasilla::BASTANTE_CLARA;
            else if (tipo == TipoCasilla::BASTANTE_CLARA) tipo = TipoCasilla::LIGERAMENTE_CLARA;
            else if (tipo == TipoCasilla::LIGERAMENTE_CLARA) tipo = TipoCasilla::LIGERAMENTE_OSCURA;
            else if (tipo == TipoCasilla::LIGERAMENTE_OSCURA) tipo = TipoCasilla::BASTANTE_OSCURA;
            else if (tipo == TipoCasilla::BASTANTE_OSCURA)tipo = TipoCasilla::OSCURA;
        }
        else {
            if (tipo == TipoCasilla::OSCURA) tipo = TipoCasilla::BASTANTE_OSCURA;
            else if (tipo == TipoCasilla::BASTANTE_OSCURA) tipo = TipoCasilla::LIGERAMENTE_OSCURA;
            else if (tipo == TipoCasilla::LIGERAMENTE_OSCURA) tipo = TipoCasilla::LIGERAMENTE_CLARA;
            else if (tipo == TipoCasilla::LIGERAMENTE_CLARA) tipo = TipoCasilla::BASTANTE_CLARA;
            else if (tipo == TipoCasilla::BASTANTE_CLARA) tipo = TipoCasilla::CLARA;
        }
    }
}


