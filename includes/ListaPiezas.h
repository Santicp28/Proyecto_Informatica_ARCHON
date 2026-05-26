#pragma once
#include<vector>
#include "Pieza.h"

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
    bool moverDeCasilla(PosicionMatriz origen, PosicionMatriz destino) {
        for (Pieza* p : listaPiezas) {
            if (p != nullptr && p->getPosicionMatriz() == origen)
            {
                p->setPosicionMatriz(destino.fila, destino.columna);
                return true;
            }

        }
        return false;
    }

    //llamar después de arena
	void piezaPierde(Pieza* p) {
        auto it = std::find(listaPiezas.begin(), listaPiezas.end(), p);
        if (it != listaPiezas.end()) {
            delete *it; //liberar memoria de la pieza
            listaPiezas.erase(it); //eliminar la pieza de la lista
        }
    }



    void dibujarPiezas(const Renderer& renderer, const Vector2D& esquinaSuperiorIzda, double longitudCasilla) const
    {
        double escalaPieza = 0.65;

        for (const auto& pieza : listaPiezas) {
            if (pieza != nullptr) {

                PosicionMatriz pos = pieza->getPosicionMatriz();

                Vector2D centroPieza{
                    esquinaSuperiorIzda.x + (pos.columna + 0.5) * longitudCasilla,
                    esquinaSuperiorIzda.y - (pos.fila + 0.5) * longitudCasilla
                };

                pieza->dibuja(renderer, centroPieza, longitudCasilla*escalaPieza, longitudCasilla*escalaPieza);
            }   
        }
    }

    //sirve para obtener la pieza que hay en una posición dada
    Pieza* getPiezaEnPosicion(PosicionMatriz pos) const
    {
        for (auto p : listaPiezas) {
            if (p != nullptr && p->getPosicionMatriz() == pos) { return p; }
        }

        return nullptr;
    }


    bool hayPiezaEn(PosicionMatriz pos) const
    {
        return getPiezaEnPosicion(pos) != nullptr;
    }



    ~ListaPiezas() { destruirPiezas(); }
};  