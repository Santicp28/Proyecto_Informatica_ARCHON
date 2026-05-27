#pragma once
#include<vector>
#include "Pieza.h"
#include "Tipos.h"

using std::vector;

class ListaPiezas
{
    vector<Pieza*> listaPiezas;

public:
    void agregar(Pieza* p) { if (std::find(listaPiezas.begin(), listaPiezas.end(), p) == listaPiezas.end()) listaPiezas.push_back(p); }
    void destruirPiezas() {
        for (auto i : listaPiezas) delete i;
        listaPiezas.clear();
    }
    //tablero se encarga de decidir si el movimiento es correcto, esta funcion solo se encarga de mover la pieza
    bool moverDeCasilla(const PosicionMatriz& origen, const PosicionMatriz& destino);

    //llamar después de arena
    void piezaPierde(Pieza* p); 

    void dibujarPiezas(const Renderer& renderer, const Vector2D& esquinaSuperiorIzda, double longitudCasilla) const;
    
    //sirve para obtener la pieza que hay en una posición dada
    Pieza* getPiezaEnPosicion(PosicionMatriz pos) const {
        for (auto p : listaPiezas)
            if (p != nullptr && p->getPosicionMatriz() == pos) {return p;}
        return nullptr;
    }

    //para saber cuando pierde un bando
    bool noQuedanPiezasDeBando(Bando b) const {
        for (auto p : listaPiezas)
            if (p != nullptr && p->getBando() == b) {return false;}
        return true;
	}

    bool hayPiezaEn(PosicionMatriz pos) const { return getPiezaEnPosicion(pos) != nullptr; }

    ~ListaPiezas() { destruirPiezas(); }
};  