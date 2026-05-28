#pragma once
#include "Casilla.h"
#include "Pieza.h"
#include <vector>
#include "Tipos.h"
#include "ListaPiezas.h"
#include "Renderer.h"
#include "Config.h"
#include "Cursor.h"
#include "Menu.h"

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
#include "PanelStats.h"
#include "PanelHechizo.h"

class Tablero {
private:

    double longitud{ Config::sizeMundo.y };
    Vector2D posicion{ Config::sizeMundo * 0.5 };//en el centro

    static constexpr int TAM = 9;
    Casilla casillas[TAM][TAM];

    ListaPiezas listaPiezas;

    Bando turnoActual;
    Bando ganador;

    Cursor cursor{ {4, 0} };

	Color colorFondoPanel{ 0.3f, 0.3f, 0.3f };
	Color colorBordePanel{ 0.9f, 0.9f, 0.9f };
	Color colorTextoPanel{ 0.9f, 0.9f, 0.9f };
	Color colorTituloPanelLuz{ 0.0f, 0.0f, 1.0f };
	Color colorTituloPanelOscuridad{ 1.0f, 0.0f, 0.0f };
   
    PanelStats* panelStatsLuz;
	PanelStats* panelStatsOscuridad;
    
        

    PosicionMatriz origenSeleccionado;
    bool hayOrigenSeleccionado = false;
    std::vector<PosicionMatriz> movimientosPosibles;

	//flag cuando dos piezas de bandos opuestos se encuentran en la misma casilla
    bool combatePendiente;

    //estas son para saber cómo terminan las piezas después de la arena
    PosicionMatriz origenCombate;
    PosicionMatriz destinoCombate;

    int contadorTurnos = 0;
	bool cicloLuz_A_Oscuridad = true; //para controlar el cambio de las casillas oscilantes

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
    bool moverPieza(PosicionMatriz origen, PosicionMatriz destino);

    bool movimientoLegal(PosicionMatriz origen, PosicionMatriz destino);
    bool caminoLibreEnL(PosicionMatriz origen, PosicionMatriz destino, bool primeroFilas) const;
	// ----- FUNCIONES DE MOVIMIENTO Y COMBATE ------ END



	// ----- FUNCIONES DE CURSOR Y SELECCIÓN ------ START
    void moverCursor(int df, int dc);
    bool seleccionarPiezasConCursor();

    bool posicionValida(PosicionMatriz pos) const;   //para asegurarnos que no nos salimos del tablero
	// ----- FUNCIONES DE CURSOR Y SELECCIÓN ------ END



	// ----- FUNCIONES MISCELÁNEAS ------ START
    bool hayCombatePendiente() const;
    void limpiarCombatePendiente(); //cuando empieza la arena se limpia el flag de combate pendiente

	void actualizarPanelStats(PanelStats* panel, const Pieza* pieza);

    bool comprobarFinJuego();
	// ------ FUNCIONES MISCELÁNEAS ------ END
    



	// ------- EFECTOS DE CASILLAS Y OTROS ------- START
    void aplicarEfectoTipoCasilla(Pieza* p, const Casilla& c);

    void curaPasiva();
	// ------- EFECTOS DE CASILLAS Y OTROS ------- END





	// ------- GETTERS ------ START
    //para saber donde está cada pieza después de que se resuelve la arena
    PosicionMatriz getOrigenCombate() const;
    PosicionMatriz getDestinoCombate() const;

	Pieza* getAtacante() const { return listaPiezas.getPiezaEnPosicion(origenCombate); }
    Pieza* getDefensor() const { return listaPiezas.getPiezaEnPosicion(destinoCombate); }

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

		aplicarEfectoTipoCasilla(p, casillas[fila][columna]);

    }


    Bando comprobarCasillasDePoder();
	// ------- FUNCIONES MISCELANEAS 2 ------- END
};