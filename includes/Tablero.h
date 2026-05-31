#pragma once
#include "Casilla.h"
#include "Config.h"
#include "ContenedorSprites.h"
#include "Cursor.h"
#include "ListaPiezas.h"
#include "Menu.h"
#include "Pieza.h"
#include "Renderer.h"
#include "Tipos.h"
#include <vector>
#include "Hechizos.h"

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


enum class EstadoTablero {
    TABLERO,
    MENU_HECHIZOS
};

class Tablero {

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
	Color colorTextoPanel{ 0.4f, 0.4f, 0.4f };
	Color colorTituloPanelLuz{ 0.0f, 0.0f, 1.0f };
	Color colorTituloPanelOscuridad{ 1.0f, 0.0f, 0.0f };
   
    PanelStats* panelStatsLuz = nullptr;
	PanelStats* panelStatsOscuridad = nullptr;
    

    //flags hechizos
	bool vamosUsarHechizo = false; //flag para saber si se ha entrado al menú de hechizos, se resetea cada vez que se termina un hechizo
	HechizoQueVoyAUsar hechizoSeleccionado; //struct de bools para saber qué hechizo se ha seleccionado en el menú de hechizos, se resetea cada vez que se usa el hechizo

    PosicionMatriz origenSeleccionado;

    PosicionMatriz primeraCasillaHechizo;
	PosicionMatriz destinoHechizoSeleccionado;

    bool hayOrigenSeleccionado = false;

	bool hayPrimeraCasillaHechizo = false;

    std::vector<PosicionMatriz> movimientosPosibles;

	//flag cuando dos piezas de bandos opuestos se encuentran en la misma casilla
    bool combatePendiente;

    //estas son para saber cómo terminan las piezas después de la arena
    PosicionMatriz origenCombate;
    PosicionMatriz destinoCombate;

	EstadoTablero estadoTablero;
	Menu menuHechizosLuz;
	Menu menuHechizosOscuridad;

    int contadorTurnos;
    int contadorTurnosParaCiclo;

    CicloLuz_A_Oscuridad ciclo;

	std::string mensajeEtapaActual = "Clara";

public:
    Tablero(double longit);
    ~Tablero() {
        delete panelStatsLuz;
        delete panelStatsOscuridad;
	}

    void inicializa();
    void moverCursor(int df, int dc);

    TableroAccion tecla(unsigned char key);


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

	Bando getGanador() const { return ganador; }

    bool resultadoCombate(Pieza* ganadorArena);
	// ------- GETTERS ------ END


private:

    // ----- FUNCIONES DE DIBUJO ------ START
    void dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites)const;

    void resaltarMovimientoPosible();
    void limpiarResaltados();

    void dibujaOrigenSeleccionado(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& posicion, double longitud) const;
    
    // ----- FUNCIONES DE DIBUJO ------ END



    // ----- FUNCIONES DE MOVIMIENTO Y COMBATE ------ START
    bool moverPieza(PosicionMatriz origen, PosicionMatriz destino);

    bool movimientoLegal(PosicionMatriz origen, PosicionMatriz destino);
    bool caminoLibreEnL(PosicionMatriz origen, PosicionMatriz destino, bool primeroFilas) const;
    // ----- FUNCIONES DE MOVIMIENTO Y COMBATE ------ END



    // ----- FUNCIONES DE SELECCIÓN DE PIEZAS ------ START
    void seleccionarPiezasConCursor();

    bool posicionValida(PosicionMatriz pos) const;   //para asegurarnos que no nos salimos del tablero
	// ----- FUNCIONES DE CURSOR Y SELECCIÓN ------ END
    

    // ----- FUNCIONES PARA HECHIZOS ----- START
   /* void seleccionar0CasillaHechizos(); */
    void seleccionar1CasillaHechizos();
	void seleccionar2CasillasHechizos();


    void limpiarHechizoSeleccionado();
	// ----- FUNCIONES PARA HECHIZOS ----- END




    // ----- FUNCIONES MISCELÁNEAS ------ START
    bool hayCombatePendiente() const;
    void limpiarCombatePendiente(); //cuando empieza la arena se limpia el flag de combate pendiente

    void actualizarPanelStats(PanelStats* panel, const Pieza* pieza);

    Bando comprobarCasillasDePoder();

    bool comprobarFinJuego();

    // ------ FUNCIONES MISCELÁNEAS ------ END

    //para después de mover o terminar la arena
    //hacer una funcion para cuando se termina el combate y aplicar los resultados
    void cambiarTurno();
    void cicloTurno();


    //plantilla para agregar piezas
    template <typename T>
    void agregarPieza(const PosicionMatriz& posicion)
    {
        Pieza* p = new T();
        p->setPosicionMatriz(posicion);
        listaPiezas.agregar(p);

		aplicarEfectoTipoCasilla(p, casillas[posicion.fila][posicion.columna]);

    }
    // ------ FUNCIONES MISCELÁNEAS ------ END
};