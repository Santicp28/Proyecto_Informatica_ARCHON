#pragma once
#include "Casilla.h"
#include "Pieza.h"
#include <vector>
#include "Tipos.h"
#include "ListaPiezas.h"
#include "Interaccion.h"
#include "Renderer.h"
#include "Config.h"
#include "Cursor.h"

#include "Arquero.h"
#include "Banshee.h"
#include "Basilisco.h"
#include "Caballero.h"
#include "Cambiaforma.h"
#include "Djinni.h"
#include "Dragon.h"
#include "Duende.h"
#include "Fenix.h"
#include "Golem.h"
#include "Hechicero.h"
#include "Mago.h"
#include "Manticora.h"
#include "Trol.h"
#include "Unicornio.h"
#include "Valquiria.h"

class Tablero {
private:
    friend class Interaccion;
    friend class Cursor;

    double longitud;
    Vector2D posicion{ Config::sizeMundo * 0.5 };//en el centro
    static constexpr int TAM = 9;
    Casilla casillas[TAM][TAM];

    ListaPiezas listaPiezas;
    Bando turnoActual;

    Cursor cursor{ {4, 0} };

    PosicionMatriz origenSeleccionado;
    bool hayOrigenSeleccionado = false;
    std::vector<PosicionMatriz> movimientosPosibles;

	//flag cuando dos piezas de bandos opuestos se encuentran en la misma casilla
    bool combatePendiente;

    //estas son para saber cómo terminan las piezas después de la arena
    PosicionMatriz origenCombate;
    PosicionMatriz destinoCombate;


public:
    void dibuja(const Renderer& renderer)const;
    void inicializa();

    bool mover(PosicionMatriz origen, PosicionMatriz destino);

    //funcion para obtener el flag si hay combate
    bool hayCombatePendiente() const;
    void limpiarCombatePendiente(); //cuando empieza la arena se limpia el flag de combate pendiente

    //para saber donde está cada pieza después de que se resuelve la arena
    PosicionMatriz getOrigenCombate() const;
    PosicionMatriz getDestinoCombate() const;

    //para saber de quién es el turno, por ejemplo para mostrar en pantalla
    Bando getTurnoActual() const;

    void moverCursor(int df, int dc);
    bool seleccionarConCursor();

    PosicionMatriz getCursor() const;
    bool getHayOrigenSeleccionado() const;
    PosicionMatriz getOrigenSeleccionado() const;

    void resaltarMovimientoPosible();
    void limpiarResaltados();

    bool movimientoLegal(PosicionMatriz origen, PosicionMatriz destino) const;
    bool caminoLibreEnL(PosicionMatriz origen, PosicionMatriz destino, bool primeroFilas) const;

    bool esMovimientoPosible(PosicionMatriz pos) const;

	void dibujaOrigenSeleccionado(const Renderer& renderer, const Vector2D& posicion, double longitud) const;

private:

    //para después de mover o terminar la arena
    //hacer una funcion para cuando se termina el combate y aplicar los resultados
      void cambiarTurno();

      //plantilla para agregar piezas
      template <typename T>
      void agregarPieza(int fila, int columna)
      {
          Pieza* p = new T();
          p->setPosicionMatriz(fila, columna);
          listaPiezas.agregar(p);
      }
};