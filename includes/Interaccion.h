#pragma once
#include "Pieza.h"
#include "Casilla.h"

class Interaccion {
public:
    void piezaEfectoTipoCasilla(Pieza& p, Casilla c) {

        if (p.bando == Bando::LUZ) {
            switch (c.getTipo()) {
            case TipoCasilla::CLARA:
                p.fuerza *= 1.2;
                break;
            case TipoCasilla::OSCURA:
                p.fuerza *= 0.8;
                break;
                //poner cada caso
            }
        }
        else {
            switch (c.getTipo()) {
            case TipoCasilla::OSCURA:
                p.fuerza *= 1.2;
                break;
            case TipoCasilla::CLARA:
                p.fuerza *= 0.8;
                break;
                //igual
            }
        }
    }

    bool posicionValida(Casilla c, int tamano) const
    {
        int fila = c.getPosicionMatriz().fila;
        int col = c.getPosicionMatriz().columna;
        return fila >= 0 && fila < tamano && col >= 0 && col < tamano;
    }

    bool mismaPosicion(const Pieza& p, const Casilla& c)
    {
        return p.getPosicionMatriz().fila == c.getPosicionMatriz().fila && p.getPosicionMatriz().columna == c.getPosicionMatriz().columna;
    }
};