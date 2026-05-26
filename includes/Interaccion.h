#pragma once
#include "Pieza.h"
#include "Casilla.h"
#include "Tipos.h"
#include "ListaPiezas.h"

class Interaccion {
public:

    //cada casilla otorga un efecto a la pieza que contiente
    //void piezaEfectoTipoCasilla(Pieza& p, Casilla c, double vidaExtra) {
    //    
    //    if (p.vida >= vidaExtra){
    //        if (p.bando == Bando::LUZ) {
    //            if (c.getTipo() == TipoCasilla::CLARA) p.vida += vidaExtra;
    //        }
    //        else {
    //            if (c.getTipo() == TipoCasilla::CLARA) p.vida += vidaExtra;
    //        }
    //    }
    //}

  //  void restaurarVida(Pieza& p) {
        //int vidaActual = p.vida;
  //      if (vidaActual)

  //  }

    //para asegurarnos que no nos salimos del tablero
    static bool posicionValida(PosicionMatriz pos)
    {
        int fila = pos.fila;
        int col = pos.columna;
        return fila >= 0 && fila < 9 && col >= 0 && col < 9;
    }

    //para saber de qué bando es la pieza de una casilla, si no hay, devuelve ninguno
    static Bando getBandoOcupante(const PosicionMatriz& pos, const ListaPiezas& listaPiezas) 
    {
        Pieza* p = listaPiezas.getPiezaEnPosicion(pos);
        if (p != nullptr) {
            return p->bando;
        }
        return Bando::NINGUNO;
    }



};