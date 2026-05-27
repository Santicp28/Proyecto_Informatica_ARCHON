#include "Casilla.h"
#include "Graftablero.h"
#include <cstdlib> 


void Casilla::inicializa(const TipoCasilla& nuevoTipo, PosicionMatriz nuevaPosicion)
{
    tipo = nuevoTipo;
    posicionMatriz = nuevaPosicion;
    
    varianteGrafico = rand() % 3;

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

    if (tipo == TipoCasilla::CLARA) {
        const ETSIDI::Sprite* variantes[] = {
            &luz1.sprite,
            &luz2.sprite,
            &luz3.sprite
        };
        renderer.dibujaSprite(*variantes[varianteGrafico], posicion, longitud * escalaPieza, longitud * escalaPieza);
    }
    else if (tipo == TipoCasilla::PODER) {
        renderer.dibujaSprite(casillaespecial.sprite, posicion, longitud * escalaPieza, longitud * escalaPieza);
    }
    else {
        const ETSIDI::Sprite* variantes[] = {
            &oscuro1.sprite,
            &oscuro2.sprite,
            &oscuro3.sprite
        };
        renderer.dibujaSprite(*variantes[varianteGrafico], posicion, longitud * escalaPieza, longitud * escalaPieza);
    }

    if (resaltada) {
        renderer.dibujaSprite(posiciones.sprite, posicion, longitud, longitud);
    }

    
}


void Casilla::cambiarOscilantes() {
	if (esOscilante) {
        if (tipo == TipoCasilla::CLARA) {
            tipo = TipoCasilla::OSCURA;
            color = { 0.f, 0.f, 0.f };//por ahora mientras no hay sprites
        }
        else if (tipo == TipoCasilla::OSCURA) {
            tipo = TipoCasilla::CLARA;
            color = { 1.f, 1.f, 1.f };
        }
    }
}


