#pragma once
#include "Pieza.h"
#include "Casilla.h"

class Interaccion {
public:

    //cada casilla otorga un efecto a la pieza que contiente
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

    //para asegurarnos que no nos salimos del tablero
    bool posicionValida(PosicionMatriz pos, int tamano) const
    {
        int fila = pos.fila;
        int col = pos.columna;
        return fila >= 0 && fila < tamano && col >= 0 && col < tamano;
	}

    //para saber de qué bando es la pieza de una casilla, si no hay, devuelve ninguno
    Bando getBandoOcupante(const PosicionMatriz& pos, const ListaPiezas& listaPiezas) const
    {
        Pieza* p = listaPiezas.getPiezaEnPosicion(pos);
        if (p != nullptr) {
            return p->bando;
        }
        return Bando::NINGUNO;
	}




};

