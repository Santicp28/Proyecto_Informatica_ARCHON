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

void Casilla::dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& posicion, double longitud) const
{
    double escalaPieza = 1.3;

    if (tipo == TipoCasilla::CLARA) renderer.dibujaCuadrado(contenedorSprites.spriteClara, posicion,Config::azul, { longitud * escalaPieza, longitud * escalaPieza });
    else if (tipo == TipoCasilla::BASTANTE_CLARA) renderer.dibujaCuadrado(contenedorSprites.spriteBastanteClara, posicion,Config::cyan, { longitud * escalaPieza, longitud * escalaPieza });
    else if (tipo == TipoCasilla::LIGERAMENTE_CLARA) renderer.dibujaCuadrado(contenedorSprites.spriteLigeramenteClara, posicion,Config::verde, { longitud * escalaPieza, longitud * escalaPieza });
    else if (tipo == TipoCasilla::LIGERAMENTE_OSCURA) renderer.dibujaCuadrado(contenedorSprites.spriteLigeramenteOscura, posicion,Config::amarillo, { longitud * escalaPieza, longitud * escalaPieza });
    else if (tipo == TipoCasilla::BASTANTE_OSCURA) renderer.dibujaCuadrado(contenedorSprites.spriteBastanteOscura, posicion,Config::naranja, { longitud * escalaPieza, longitud * escalaPieza });
    else if (tipo == TipoCasilla::OSCURA) renderer.dibujaCuadrado(contenedorSprites.spriteOscura, posicion,Config::rojo, { longitud * escalaPieza, longitud * escalaPieza });
	else if (tipo == TipoCasilla::PODER) renderer.dibujaCuadrado(contenedorSprites.spriteCasillaEspecial, posicion,Config::morado, { longitud * escalaPieza, longitud * escalaPieza });

    if (resaltada) {
        renderer.dibujaContornoCuadrado(contenedorSprites.spriteElegido, posicion,Config::verdeOscuro, { longitud, longitud });
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


