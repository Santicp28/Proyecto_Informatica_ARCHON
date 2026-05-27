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
#include"Menu.h"

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

    double longitud{ Config::sizeMundo.y };
    Vector2D posicion{ Config::sizeMundo * 0.5 };//en el centro
    static constexpr int TAM = 9;
    Casilla casillas[TAM][TAM];

    ListaPiezas listaPiezas;
    Bando turnoActual;
    Bando ganador;

    Cursor cursor{ {4, 0} };

    PosicionMatriz origenSeleccionado;
    bool hayOrigenSeleccionado = false;
    std::vector<PosicionMatriz> movimientosPosibles;

	//flag cuando dos piezas de bandos opuestos se encuentran en la misma casilla
    bool combatePendiente;

    //estas son para saber cómo terminan las piezas después de la arena
    PosicionMatriz origenCombate;
    PosicionMatriz destinoCombate;

    int contadorTurnos = 0;

public:
	Tablero(double longit) : longitud(longit) {}

    void inicializa();


    // ----- FUNCIONES DE DIBUJO ------ START
    void dibuja(const Renderer& renderer)const;

    void resaltarMovimientoPosible();
    void limpiarResaltados();

    void dibujaOrigenSeleccionado(const Renderer& renderer, const Vector2D& posicion, double longitud) const;
    // ----- FUNCIONES DE DIBUJO ------ END



	// ----- FUNCIONES DE MOVIMIENTO Y COMBATE ------ START
    bool mover(PosicionMatriz origen, PosicionMatriz destino);

    bool movimientoLegal(PosicionMatriz origen, PosicionMatriz destino) const;
    bool caminoLibreEnL(PosicionMatriz origen, PosicionMatriz destino, bool primeroFilas) const;

    bool esMovimientoPosible(PosicionMatriz pos) const;
	// ----- FUNCIONES DE MOVIMIENTO Y COMBATE ------ END



	// ----- FUNCIONES DE CURSOR Y SELECCIÓN ------ START
    void moverCursor(int df, int dc);
    bool seleccionarConCursor();
	// ----- FUNCIONES DE CURSOR Y SELECCIÓN ------ END



	// ----- FUNCIONES MISCELÁNEAS ------ START
    bool hayCombatePendiente() const;
    void limpiarCombatePendiente(); //cuando empieza la arena se limpia el flag de combate pendiente

    bool comprobarFinJuego();
	// ------ FUNCIONES MISCELÁNEAS ------ END
    


	// ------- GETTERS ------ START
    //para saber donde está cada pieza después de que se resuelve la arena
    PosicionMatriz getOrigenCombate() const;
    PosicionMatriz getDestinoCombate() const;

    //para saber de quién es el turno, por ejemplo para mostrar en pantalla
    Bando getTurnoActual() const;

    bool getHayOrigenSeleccionado() const;
    PosicionMatriz getOrigenSeleccionado() const;


	Bando getGanador() const { return ganador; }
	// ------- GETTERS ------ END


private:

	// ------- FUNCIONES MISCELANEAS 2 ------- START
    //para después de mover o terminar la arena
    //hacer una funcion para cuando se termina el combate y aplicar los resultados
    void cambiarTurno();
    void cicloTurno();

    //plantilla para agregar piezas
    template <typename T>
    void agregarPieza(int fila, int columna)
    {
        Pieza* p = new T();
        p->setPosicionMatriz(fila, columna);
        listaPiezas.agregar(p);
    }

    Bando comprobarCasillasDePoder();
	// ------- FUNCIONES MISCELANEAS 2 ------- END
};