#pragma once
#include<vector>
#include "Pieza.h"

using std::vector;

class ListaPiezas
{
    vector<Pieza*> listaPiezas;
public:
    void agregar(Pieza* p) { if (std::find(listaPiezas.begin(), listaPiezas.end(), p) == listaPiezas.end()) listaPiezas.push_back(p); }//comprueba  si ya existe esa dirección, sino la añade
    void dibuja(Vector2D esquina_arriba_izda, double size_celda) const { for (auto p : listaPiezas)p->dibuja(esquina_arriba_izda, size_celda); }
    

    void destruirPiezas() {
        for (auto i : listaPiezas) delete i;
        listaPiezas.clear();
    }

    void moverDeCasilla(const Casilla& origen, const Casilla& destino) {
        for (auto p : listaPiezas) {
            if (p->getPosicionMatriz().fila == origen.getPosicionMatriz().fila && p->getPosicionMatriz().columna == origen.getPosicionMatriz().columna) 
            {
                p->setPosicionMatriz(destino.getPosicionMatriz().fila, destino.getPosicionMatriz().columna);
                break;
            }
        }
	}

	void piezaPierde(Pieza* p) {
        auto it = std::find(listaPiezas.begin(), listaPiezas.end(), p);
        if (it != listaPiezas.end()) {
            delete *it; // Liberar memoria de la pieza
            listaPiezas.erase(it); // Eliminar la pieza de la lista
        }
    }


    ~ListaPiezas() { destruirPiezas(); }


};