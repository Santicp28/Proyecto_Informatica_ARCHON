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


void Casilla::cambiarOscilantes(int cicloLuz_A_Oscuridad) {
    if (esOscilante) {
        if (cicloLuz_A_Oscuridad) {
            if (tipo == TipoCasilla::CLARA) {
                tipo = TipoCasilla::BASTANTE_CLARA;
                color = { 0.10f, 0.80f, 0.76f };//por ahora mientras no hay sprites
            }
            else if (tipo == TipoCasilla::BASTANTE_CLARA) {
                tipo = TipoCasilla::LIGERAMENTE_CLARA;
                color = { 0.00f, 0.65f, 0.07f };
            }
            else if (tipo == TipoCasilla::LIGERAMENTE_CLARA) {
                tipo = TipoCasilla::LIGERAMENTE_OSCURA;
                color = { 0.55f, 0.25f, 0.60f };
            }
            else if (tipo == TipoCasilla::LIGERAMENTE_OSCURA) {
                tipo = TipoCasilla::BASTANTE_OSCURA;
                color = { 0.15f, 0.00f, 0.60f };
            }
            else if (tipo == TipoCasilla::BASTANTE_OSCURA) {
                tipo = TipoCasilla::OSCURA;
                color = { 0.f, 0.f, 0.f };
            }
        }
        else {
            if (tipo == TipoCasilla::OSCURA) {
                tipo = TipoCasilla::BASTANTE_OSCURA;
                color = { 0.15f, 0.00f, 0.60f };
            }
            else if (tipo == TipoCasilla::BASTANTE_OSCURA) {
                tipo = TipoCasilla::LIGERAMENTE_OSCURA;
                color = { 0.55f, 0.25f, 0.60f };
            }
            else if (tipo == TipoCasilla::LIGERAMENTE_OSCURA) {
                tipo = TipoCasilla::LIGERAMENTE_CLARA;
                color = { 0.00f, 0.65f, 0.07f };
            }
            else if (tipo == TipoCasilla::LIGERAMENTE_CLARA) {
                tipo = TipoCasilla::BASTANTE_CLARA;
                color = { 0.10f, 0.80f, 0.76f };
            }
            else if (tipo == TipoCasilla::BASTANTE_CLARA) {
                tipo = TipoCasilla::CLARA;
                color = { 1.f, 1.f, 1.f };
            }

        }
    }
}


