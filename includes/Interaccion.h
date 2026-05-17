#pragma once
#include "Pieza.h"
#include "Casilla.h"

class Interaccion {
    void piezaEfectoTipoCasilla(Pieza* p, Casilla c) {

        if (p->tipo == OSCURO) {

            switch (c.getTipo()) {
            case TipoCasilla::OSCURA:
                p->fuerza *= 0.8;
                break;

            case TipoCasilla::CLARA:
                p->fuerza *= 1.2;
				break;



            }
        }
    }
};