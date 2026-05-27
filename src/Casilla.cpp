#include "Casilla.h"


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
    renderer.dibujaCuadrado(posicion, color, { longitud,longitud });
    renderer.dibujaContornoCuadrado(posicion, { 0.5f, 0.5f, 0.5f }, { longitud,longitud });

    if (tipo == TipoCasilla::CLARA) {
		//renderer.dibujaSprite("bin/Graficos/clara.png", posicion, longitud, longitud);
    }
    else if (tipo == TipoCasilla::PODER) {
        //renderer.dibujaSprite("bin/Graficos/poder.png", posicion, longitud, longitud);
    }
    else {
		//renderer.dibujaSprite("bin/Graficos/oscura.png", posicion, longitud, longitud);
    }

    if (resaltada) {
        renderer.dibujaSprite("bin/Graficos/posiciones.png", posicion, longitud, longitud);
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


