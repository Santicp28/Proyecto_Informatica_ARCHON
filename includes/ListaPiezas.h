#pragma once
#include<vector>
#include "Pieza.h"

using std::vector;

class ListaPiezas
{
    vector<Pieza*> listaPiezas;

public:
    void agregar(Pieza* p) { if (std::find(listaPiezas.begin(), listaPiezas.end(), p) == listaPiezas.end()) listaPiezas.push_back(p); }
    void dibuja(Vector2D esquina_arriba_izda, double size_celda) const { for (auto p : listaPiezas)p->dibuja(esquina_arriba_izda, size_celda); }
    

    void destruirPiezas() {
        for (auto i : listaPiezas) delete i;
        listaPiezas.clear();
    }


    //tablero se encarga de decidir si el movimiento es correcto, esta funcion solo se encarga de mover la pieza
    bool moverDeCasilla(PosicionMatriz origen, PosicionMatriz destino) {
        for (Pieza* p : listaPiezas) {
            if (p->getPosicionMatriz() == origen)
            {
				return p->mover(destino); //HACER MOVER PARA CADA TIPO DE PIEZA !!!!!!
            }
        }
    }

    //llamar después de arena
	void piezaPierde(Pieza* p) {
        auto it = std::find(listaPiezas.begin(), listaPiezas.end(), p);
        if (it != listaPiezas.end()) {
            delete *it; //liberar memoria de la pieza
            listaPiezas.erase(it); //eliminar la pieza de la lista
        }
    }

    //sirve para obtener la pieza que hay en una posición dada
    Pieza* getPiezaEnPosicion(PosicionMatriz pos) const
    {
        for (auto p : listaPiezas) {
            if (p != nullptr && p->getPosicionMatriz() == pos) {return p;}
        }

        return nullptr;
    }

    ~ListaPiezas() { destruirPiezas(); }


};  