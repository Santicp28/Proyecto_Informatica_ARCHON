#include "ListaPiezas.h"

bool ListaPiezas::moverDeCasilla(const PosicionMatriz& origen, const PosicionMatriz& destino)
{
    for (Pieza* p : listaPiezas) {
        if (p != nullptr && p->getPosicionMatriz() == origen)
        {
            p->setPosicionMatriz(destino.fila, destino.columna);
            return true;
        }
    }
}

void ListaPiezas::piezaPierde(Pieza* p)
{
    auto it = std::find(listaPiezas.begin(), listaPiezas.end(), p);
    if (it != listaPiezas.end()) {
        delete* it; //liberar memoria de la pieza
        listaPiezas.erase(it); //eliminar la pieza de la lista
    }
}

void ListaPiezas::dibujarPiezas(const Renderer& renderer, const Vector2D& esquinaSuperiorIzda, double longitudCasilla) const
{
    double escalaPieza = 0.65;

    for (const auto& pieza : listaPiezas) {
        if (pieza != nullptr) {

            PosicionMatriz pos = pieza->getPosicionMatriz();

            Vector2D centroPieza{
                esquinaSuperiorIzda.x + (pos.columna + 0.5) * longitudCasilla,
                esquinaSuperiorIzda.y + (pos.fila + 0.5) * longitudCasilla
            };

            pieza->dibuja(renderer, centroPieza, longitudCasilla * escalaPieza, longitudCasilla * escalaPieza);
        }
    }
}