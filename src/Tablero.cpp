#include "Tablero.h"
#include "Renderer.h"
#include <iostream>
#include "Graftablero.h"
#include "Grafarena.h"
using enum TipoCasilla;

Tablero::Tablero(double longit):
	longitud(longit), estadoTablero(EstadoTablero::TABLERO),
	turnoActual(Bando::AZUL),
	ganador(Bando::NINGUNO),
	combatePendiente(false),
	hayOrigenSeleccionado(false),
	contadorTurnos(0),
    contadorTurnosParaCiclo(0),
	ciclo({true}),
    menuHechizosAZUL({ "SALIR","TP","CURAR","TIEMPO","SWITCH","CARCEL","V.AGUA" },
        { MenuAccion::SALIR, MenuAccion::TP, MenuAccion::CURAR, MenuAccion::CAMBIAR_TIEMPO, MenuAccion::INTERCAMBIAR, MenuAccion::ENCARCELAR, MenuAccion::VASO_DE_AGUA },
        { (Config::sizeMundo.x - Config::sizeMundo.y) * 0.5, Config::sizeMundo.y },
        { (Config::sizeMundo.x - Config::sizeMundo.y) * 0.5 * 0.5, Config::sizeMundo.y * 0.5 }, "AZUL", { 1.0f, 0.0f, 0.0f }),

    menuHechizosROJO({ "SALIR","TP","CURAR","TIEMPO","SWITCH","CARCEL","V.AGUA" },
        { MenuAccion::SALIR, MenuAccion::TP, MenuAccion::CURAR, MenuAccion::CAMBIAR_TIEMPO, MenuAccion::INTERCAMBIAR, MenuAccion::ENCARCELAR, MenuAccion::VASO_DE_AGUA },
        { (Config::sizeMundo.x - Config::sizeMundo.y) * 0.5, Config::sizeMundo.y },
        { (Config::sizeMundo.x - Config::sizeMundo.y) * 0.5 * 0.5, Config::sizeMundo.y * 0.5 }, "ROJO", { 0.0f, 1.0f, 0.0f })
{
}


void Tablero::inicializa()
{

    cursor.setPosicion({ 4, 0 });

    listaPiezas.destruirPiezas();

	estadoTablero = EstadoTablero::TABLERO;

	menuHechizosAZUL.inicializa();
	menuHechizosROJO.inicializa();

    contadorTurnos = 0;
    contadorTurnosParaCiclo = 0; 
    ciclo.valor = true;

	ganador = Bando::NINGUNO;
    turnoActual = Bando::AZUL;

	combatePendiente = false;
    hayOrigenSeleccionado = false;

	//INICIALIZA CASILLAS
    constexpr TipoCasilla tipoCasillas[TAM_TABLERO][TAM_TABLERO] =
    {
     { ROJA,     AZUL,     ROJA,     OSCILANTE,  PODER,      OSCILANTE,  AZUL,     ROJA,     AZUL     },
     { AZUL,      ROJA,    OSCILANTE,  AZUL,      OSCILANTE,  ROJA,      OSCILANTE,  AZUL,    ROJA      },
     { ROJA,     OSCILANTE, AZUL,      ROJA,     OSCILANTE,  AZUL,     ROJA,      OSCILANTE, AZUL     },
     { OSCILANTE,  AZUL,     ROJA,     AZUL,      OSCILANTE,  ROJA,      AZUL,     ROJA,     OSCILANTE  },
     { PODER,      OSCILANTE, OSCILANTE,  OSCILANTE,  PODER,      OSCILANTE,  OSCILANTE,  OSCILANTE, PODER      },
     { OSCILANTE,  AZUL,     ROJA,     AZUL,      OSCILANTE,  ROJA,      AZUL,     ROJA,     OSCILANTE  },
     { ROJA,     OSCILANTE, AZUL,      ROJA,     OSCILANTE,  AZUL,     ROJA,      OSCILANTE, AZUL     },
     { AZUL,      ROJA,    OSCILANTE,  AZUL,      OSCILANTE,  ROJA,      OSCILANTE,  AZUL,    ROJA      },
     { ROJA,     AZUL,     ROJA,     OSCILANTE,  PODER,      OSCILANTE,  AZUL,     ROJA,     AZUL     }
    };
    for (int f = 0; f < TAM_TABLERO; f++) {
        for (int c = 0; c < TAM_TABLERO; c++) {
            casillas[f][c].inicializa(tipoCasillas[f][c], { f, c });
        }
    }

    //INICIALIZA CASILLAS


    // ------------- INICIALIZA PIEZAS --------- PONER SU POSICION INICIAL
    // ------COLUMNA 0
    agregarPieza<Valquiria>({ 0, 0 });
    agregarPieza<Golem>({ 1, 0 });
    agregarPieza<Unicornio>({ 2, 0 });
    agregarPieza<Djinni>({ 3, 0 });
    agregarPieza<Mago>({ 4, 0 });
    agregarPieza<Fenix>({ 5, 0 });
    agregarPieza<Unicornio>({ 6, 0 });
    agregarPieza<Golem>({ 7, 0 });
    agregarPieza<Valquiria>({ 8, 0 });


    //------COLUMNA 1
    agregarPieza<Arquero>({ 0, 1 });
    agregarPieza<Caballero>({ 1, 1 });
    agregarPieza<Caballero>({ 2, 1 });
    agregarPieza<Caballero>({ 3, 1 });
    agregarPieza<Caballero>({ 4, 1 });
    agregarPieza<Caballero>({ 5, 1 });
    agregarPieza<Caballero>({ 6, 1 });
    agregarPieza<Caballero>({ 7, 1 });
    agregarPieza<Arquero>({ 8, 1 });


    //------COLUMNA 7
    agregarPieza<Manticora>({ 0, 7 });
    agregarPieza<Duende>({ 1, 7 });
    agregarPieza<Duende>({ 2, 7 });
    agregarPieza<Duende>({ 3, 7 });
    agregarPieza<Duende>({ 4, 7 });
    agregarPieza<Duende>({ 5, 7 });
    agregarPieza<Duende>({ 6, 7 });
    agregarPieza<Duende>({ 7, 7 });
    agregarPieza<Manticora>({ 8, 7 });


    // ------COLUMNA 8
    agregarPieza<Banshee>({ 0, 8 });
    agregarPieza<Trol>({ 1, 8 });
    agregarPieza<Basilisco>({ 2, 8 });
    agregarPieza<Cambiaforma>({ 3, 8 });
    agregarPieza<Hechicero>({ 4, 8 });
    agregarPieza<Dragon>({ 5, 8 });
    agregarPieza<Basilisco>({ 6, 8 });
    agregarPieza<Trol>({ 7, 8 });
    agregarPieza<Banshee>({ 8, 8 });

    float referencia = (Config::anchoVentana + Config::altoVentana) * 0.5f;

    panelStatsAZUL = new PanelStats{
        {Config::sizeMundo.x * 0.12, Config::sizeMundo.y * 0.42},
        { posicion.x + longitud / 1.7, posicion.y - longitud / 1.7},
        colorFondoPanel, colorTextoPanel, colorTituloPanelAZUL, colorBordePanel, "AZUL"
    };

    panelStatsROJO = new PanelStats{
        {Config::sizeMundo.x * 0.12, Config::sizeMundo.y * 0.42},
        { posicion.x + longitud / 1.7, posicion.y - longitud / 1.9 + Config::sizeMundo.y * 0.42},
		colorFondoPanel, colorTextoPanel, colorTituloPanelROJO, colorBordePanel, "ROJO"
    };

	//inicializo panel de stats con la pieza que está debajo del cursor al inicio
	if (turnoActual == Bando::AZUL) actualizarPanelStats(panelStatsAZUL, listaPiezas.getPiezaEnPosicion(cursor.getPosicion()));
    else actualizarPanelStats(panelStatsROJO, listaPiezas.getPiezaEnPosicion(cursor.getPosicion()));

    vamosUsarHechizo = false;
    limpiarHechizoSeleccionado();
    mensajeEtapaActual = "Azul";
}


TableroAccion Tablero::tecla(unsigned char key)
{
    switch (estadoTablero)
    {
    case EstadoTablero::TABLERO:
    {
        switch (key)
        {
        case '\r':// ENTER
        {
            if (comprobarFinJuego()) {
                return  TableroAccion::IR_FIN_PARTIDA;
            }

            if (vamosUsarHechizo) {
				if (hechizoSeleccionado.curar || hechizoSeleccionado.encarcelar || hechizoSeleccionado.vasoDeAgua) seleccionar1CasillaHechizos();
                else if (hechizoSeleccionado.tp || hechizoSeleccionado.intercambiar) seleccionar2CasillasHechizos();
            }
            else seleccionarPiezasConCursor();


            
            //tablero avisa de que se he elegido combate, haciendo que juego ponga el estado ARENA y limpiando el flag del combate pendiente para no volver a entrar 
            if (hayCombatePendiente()) {
                limpiarCombatePendiente();
                return TableroAccion::IR_ARENA;
            }
            break;
        }
        case '\x1B': case 'P': case 'p':// '\x1B'==ESC
            return  TableroAccion::IR_PAUSA;

        case 'h': case 'H':
        {
            if(hayOrigenSeleccionado) return TableroAccion::NINGUNA;

            Pieza* mago = listaPiezas.getPiezaPorTipo(TipoPieza::MAGO);
			Pieza* hechicero = listaPiezas.getPiezaPorTipo(TipoPieza::HECHICERO);
			
            //si el que usa hechizos de cada bando está en la carcel o está muerto, no se pueden usar hechizos
            if (turnoActual == Bando::AZUL) {
				if (mago == nullptr || mago->estaEncarcelada()) return TableroAccion::NINGUNA;
                else {
                    menuHechizosAZUL.recolocarSeleccion();
                    estadoTablero = EstadoTablero::MENU_HECHIZOS;
                }
            }
            else if (turnoActual == Bando::ROJO) {
                if (hechicero == nullptr || hechicero->estaEncarcelada()) return TableroAccion::NINGUNA;
				else {
                    menuHechizosROJO.recolocarSeleccion();
                    estadoTablero = EstadoTablero::MENU_HECHIZOS;
                }
            }
            break;
        }
        case'f': case 'F':
            return TableroAccion::IR_FIN_PARTIDA;
        default:
            return TableroAccion::NINGUNA;
        }
        break;
    }
    case EstadoTablero::MENU_HECHIZOS:
    {
        MenuAccion accion = MenuAccion::NINGUNA;
        if (turnoActual == Bando::AZUL)
            accion = menuHechizosAZUL.tecla(key);
        else if (turnoActual == Bando::ROJO)
            accion = menuHechizosROJO.tecla(key);
        switch (accion)
        {
        case MenuAccion::TP: {
            limpiarHechizoSeleccionado();
            vamosUsarHechizo = true;
			hechizoSeleccionado.tp = true;
            estadoTablero = EstadoTablero::TABLERO; 
		    break;
        }
        case MenuAccion::CURAR: {
            limpiarHechizoSeleccionado();
            vamosUsarHechizo = true;
            hechizoSeleccionado.curar = true;
            estadoTablero = EstadoTablero::TABLERO; //no se por qué pone error 
            break;
        }
        case MenuAccion::CAMBIAR_TIEMPO: {
            limpiarHechizoSeleccionado();
            Hechizos::cambiarCiclo(ciclo, contadorTurnosParaCiclo, casillas);
            aplicarDebuffPorUsoHechizo();
            vamosUsarHechizo = false;
            estadoTablero = EstadoTablero::TABLERO;
            cambiarTurno();
            break;
		}
        case MenuAccion::INTERCAMBIAR: {
            limpiarHechizoSeleccionado();
            vamosUsarHechizo = true;
            hechizoSeleccionado.intercambiar = true;
            estadoTablero = EstadoTablero::TABLERO;
			break;
        }
        case MenuAccion::ENCARCELAR: {
            limpiarHechizoSeleccionado();
            vamosUsarHechizo = true;
            hechizoSeleccionado.encarcelar = true;
            estadoTablero = EstadoTablero::TABLERO;
			break;
        }
        case MenuAccion::VASO_DE_AGUA: {
            limpiarHechizoSeleccionado();
            vamosUsarHechizo = true;
			hechizoSeleccionado.vasoDeAgua = true;
            estadoTablero = EstadoTablero::TABLERO; 
            break;
        }
        case MenuAccion::SALIR:
        {
            limpiarHechizoSeleccionado();
            vamosUsarHechizo = false;
            estadoTablero = EstadoTablero::TABLERO;
            break;
        }
        default:
        {
            estadoTablero = EstadoTablero::MENU_HECHIZOS;
            break;
        }
        break;
        }
        return TableroAccion::NINGUNA;
    }
    default:
        return TableroAccion::NINGUNA;
    }
}


// --------------- FUNCIONES DE DIBUJO ------------------ START
void Tablero::dibuja(const Renderer& renderer)const {
    renderer.dibujaSprite(mesa.sprite, posicion, Config::sizeMundo.x, Config::sizeMundo.y);
    renderer.dibujaSprite(hoja.sprite, posicion, Config::sizeMundo.x * 0.6, Config::sizeMundo.y * 0.8);

	if (estadoTablero != EstadoTablero::MENU_HECHIZOS) {

        double xIzq = (Config::sizeMundo.x - Config::sizeMundo.y) - 100;
        double yBase = Config::sizeMundo.y - 400;

        /*renderer.dibujaTexto("Turno de:" + std::string((turnoActual == Bando::LUZ) ? "LUZ" : "OSCURIDAD"),
            { xIzq, yBase }, { 0.0f, 0.0f, 0.0f }, 14, AlineacionTexto::CENTRADO);
        renderer.dibujaTexto("Ciclo hacia:" + std::string((ciclo.valor) ? "OSCURIDAD" : "LUZ"),
            { xIzq, yBase + 30 }, { 0.0f, 0.0f, 0.0f }, 14, AlineacionTexto::CENTRADO);
        renderer.dibujaTexto("Etapa:" + mensajeEtapaActual,
            { xIzq, yBase + 60 }, { 0.0f, 0.0f, 0.0f }, 14, AlineacionTexto::CENTRADO);*/

        renderer.dibujaTexto("Turno:",
            { xIzq, yBase }, { 0.0f, 0.0f, 0.0f }, 14, AlineacionTexto::CENTRADO);
        renderer.dibujaTexto((turnoActual == Bando::AZUL) ? "AZUL" : "ROJO",
            { xIzq, yBase + 20 }, { 0.0f, 0.0f, 0.0f }, 14, AlineacionTexto::CENTRADO);

        renderer.dibujaTexto("Ciclo:",
            { xIzq, yBase + 50 }, { 0.0f, 0.0f, 0.0f }, 14, AlineacionTexto::CENTRADO);
        renderer.dibujaTexto((ciclo.valor) ? "->ROJO" : "->AZUL",
            { xIzq, yBase + 70 }, { 0.0f, 0.0f, 0.0f }, 14, AlineacionTexto::CENTRADO);

        renderer.dibujaTexto("Etapa:",
            { xIzq, yBase + 100 }, { 0.0f, 0.0f, 0.0f }, 14, AlineacionTexto::CENTRADO);
        renderer.dibujaTexto(mensajeEtapaActual,
            { xIzq, yBase + 120 }, { 0.0f, 0.0f, 0.0f }, 12, AlineacionTexto::CENTRADO);
    }
	

    double longitudCasilla = longitud / TAM_TABLERO;
    Vector2D esquinaSuperiorIzda{ posicion.x - longitud / 2.0, posicion.y - longitud / 2.0 };
    for (unsigned int f = 0; f < TAM_TABLERO; f++) {
        for (unsigned int c = 0; c < TAM_TABLERO; c++) {
            Vector2D centroCasilla{ esquinaSuperiorIzda.x + (c + 0.5) * longitudCasilla, esquinaSuperiorIzda.y + (f + 0.5) * longitudCasilla };
             casillas[f][c].dibuja(renderer, centroCasilla, longitudCasilla);
        }
    }

    
	listaPiezas.dibujarPiezas(renderer, esquinaSuperiorIzda, longitudCasilla);
    dibujaOrigenSeleccionado(renderer, esquinaSuperiorIzda, longitudCasilla);
    cursor.dibuja(renderer, esquinaSuperiorIzda, longitudCasilla, turnoActual);

	if (estadoTablero == EstadoTablero::MENU_HECHIZOS && turnoActual == Bando::AZUL) {
		menuHechizosAZUL.dibuja(renderer);
	}
	else if (estadoTablero == EstadoTablero::MENU_HECHIZOS && turnoActual == Bando::ROJO) {
		menuHechizosROJO.dibuja(renderer);
	}

	panelStatsAZUL->dibuja(renderer);
	panelStatsROJO->dibuja(renderer);

    if (ganador == Bando::AZUL){
        renderer.dibujaSprite(finluz.sprite, posicion, Config::sizeMundo.x, Config::sizeMundo.y);
    }
    else if (ganador == Bando::ROJO) {
        renderer.dibujaSprite(finoscuro.sprite, posicion, Config::sizeMundo.x, Config::sizeMundo.y);
    }
    if (ganador != Bando::NINGUNO){
        renderer.dibujaTexto("TAB PARA CONTINUAR", { 40.0, 40.0 }, { 0.0f, 0.0f, 0.0f }, 20, AlineacionTexto::IZQUIERDA);
    }
	panelStatsAZUL->dibuja(renderer);
	panelStatsROJO->dibuja(renderer);
}



void Tablero::resaltarMovimientoPosible()
{

    limpiarResaltados();
    if (estadoTablero == EstadoTablero::TABLERO) {
        if (!hayOrigenSeleccionado) {
            return;
        }

        for (int f = 0; f < TAM_TABLERO; f++) {
            for (int c = 0; c < TAM_TABLERO; c++) {
                PosicionMatriz destino_posible{ f,c };

                if (movimientoLegal(origenSeleccionado, destino_posible)) {
                    movimientosPosibles.push_back(destino_posible);
                    casillas[f][c].setResaltada(true);
                }
            }
        }
    }
    else if (estadoTablero == EstadoTablero::MENU_HECHIZOS) {
        //aquí habría que resaltar las casillas a las que se podría aplicar el hechizo seleccionado, pero como no hay hechizos implementados no se hace nada
	}
    
}

void Tablero::limpiarResaltados() {
    for (int f = 0; f < TAM_TABLERO; f++) {
        for (int c = 0; c < TAM_TABLERO; c++) {
            casillas[f][c].setResaltada(false);
        }
    }
    movimientosPosibles.clear();
}

void Tablero::dibujaOrigenSeleccionado(const Renderer& renderer, const Vector2D& esquinaSuperiorIzda, double longitud) const
{
    Vector2D centro{
        esquinaSuperiorIzda.x + (origenSeleccionado.columna + 0.5) * longitud,
        esquinaSuperiorIzda.y + (origenSeleccionado.fila + 0.5) * longitud
    };

    if (hayOrigenSeleccionado) {
        renderer.dibujaSprite(elegido.sprite, centro, longitud, longitud);
    }
}

// --------------- FUNCIONES DE DIBUJO ------------------ END





// --------------- LOGICA DE MOVIMIENTO ------------------ START

bool Tablero::moverPieza(PosicionMatriz origen, PosicionMatriz destino) 
{
    if (!movimientoLegal(origen, destino)) return false;
        
    Pieza* atacante = listaPiezas.getPiezaEnPosicion(origen);
    Pieza* defensor = listaPiezas.getPiezaEnPosicion(destino);

    //ILUMINAR O DESTACAR CASILLA SI HAY ERROR O MOSTRAR UN SONIDO O ALGO, TAMBIEN MOSTRAR MENSAJE PARA SABER EL ERROR

    //Si hay enemigo, no movemos todavía
    //Dejamos marcado que tiene que abrirse la arena
    if (defensor != nullptr) {
		aplicarEfectoTipoCasilla(atacante, casillas[destino.fila][destino.columna]); 
        //Se actualizan los valores antes de entrar a la arena, ya que pelean en la casilla destino y esa es la que aplica.
		//haciendo que si el atacante gana, se queda con la misma defensa con la que entraba (la de destino) y si el defensor gana se queda con la misma ya que no se mueve de casilla.

        combatePendiente = true; //FLAG PARA CAMBIAR A ARENA
        printf("combate pendiente activado, origen=(%d,%d) destino=(%d,%d)\n",
            origen.fila, origen.columna, destino.fila, destino.columna);
        origenCombate = origen;
        destinoCombate = destino;

        atacante->setEnArena(true);
        defensor->setEnArena(true);

        return true;
    }

    //Movimiento normal
	listaPiezas.moverDeCasilla(origen, destino);
    aplicarEfectoTipoCasilla(listaPiezas.getPiezaEnPosicion(destino), casillas[destino.fila][destino.columna]); //para que se actualicen los valores de defensa y poder verlos en tiempo real, a efectos prácticos solo necesiTAM_TABLEROos aplicarlos antes de arena

    cambiarTurno();


    return true;
}


bool Tablero::movimientoLegal(PosicionMatriz origen, PosicionMatriz destino) 
{

    Pieza* atacante = listaPiezas.getPiezaEnPosicion(origen);
    Pieza* defensor = listaPiezas.getPiezaEnPosicion(destino);

    if (defensor != nullptr && defensor->getBando() == atacante->getBando()) return false; //Hay una pieza aliada en destino

    if (!atacante->puedeMoverseA(destino)) return false; //esa pieza no permite ese movimiento

    if (atacante->getTipoMovimiento() == TipoMovimiento::CAMINA) {
        if (!caminoLibreEnL(origen, destino, true) && !caminoLibreEnL(origen, destino, false)) return false;
    }//si la pieza vuela o se teletransporta no hace falta comprobar el camino

    return true;
}


bool Tablero::caminoLibreEnL(PosicionMatriz origen, PosicionMatriz destino, bool primeroFilas) const //primero avanza por filas y luego por columnas para comprobar el camino en L, para comprobar las distintas posibilidades de camino. Se llama 2 veces.
{
    PosicionMatriz actual = origen;

    if (primeroFilas) {
        while (actual.fila != destino.fila) {
            if (destino.fila > actual.fila)
                actual.fila++;
            else
                actual.fila--;

            if (actual != destino && listaPiezas.hayPiezaEn(actual))
                return false;
        }

        while (actual.columna != destino.columna) {
            if (destino.columna > actual.columna)
                actual.columna++;
            else
                actual.columna--;

            if (actual != destino && listaPiezas.hayPiezaEn(actual))
                return false;
        }
    }
    else {
        while (actual.columna != destino.columna) {
            if (destino.columna > actual.columna)
                actual.columna++;
            else
                actual.columna--;

            if (actual != destino && listaPiezas.hayPiezaEn(actual))
                return false;
        }

        while (actual.fila != destino.fila) {
            if (destino.fila > actual.fila)
                actual.fila++;
            else
                actual.fila--;

            if (actual != destino && listaPiezas.hayPiezaEn(actual))
                return false;
        }
    }

    return true;
}

// --------------- LOGICA DE MOVIMIENTO ------------------ END






// ----------------- FUNCIONES DE CURSOR ----------------- START

// MOSTRAR STATS DE LA PIEZA EN LA QUE TENGO EL CURSOR!!!!!!!!!
void Tablero::moverCursor(int df, int dc)
{
	PosicionMatriz nuevaPosicion = { cursor.getPosicion().fila + df, cursor.getPosicion().columna + dc };

    if (posicionValida(nuevaPosicion)) cursor.mover(df, dc);
    
	Pieza* piezaEnCursor = listaPiezas.getPiezaEnPosicion(cursor.getPosicion());
	Bando bandoPiezaEnCursor = (piezaEnCursor != nullptr) ? piezaEnCursor->getBando() : Bando::NINGUNO;

    if (!hayOrigenSeleccionado) {
         if (bandoPiezaEnCursor == Bando::AZUL) {
             actualizarPanelStats(panelStatsAZUL, listaPiezas.getPiezaEnPosicion(cursor.getPosicion()));
             actualizarPanelStats(panelStatsROJO, nullptr);
         }
         else if (bandoPiezaEnCursor == Bando::ROJO) {
             actualizarPanelStats(panelStatsAZUL, nullptr);
             actualizarPanelStats(panelStatsROJO, listaPiezas.getPiezaEnPosicion(cursor.getPosicion()));
         }
         else {
             actualizarPanelStats(panelStatsROJO, nullptr);
			 actualizarPanelStats(panelStatsAZUL, nullptr);
         }
    }
    else {
        if (turnoActual == Bando::AZUL) {
            if (bandoPiezaEnCursor == Bando::ROJO) actualizarPanelStats(panelStatsROJO, listaPiezas.getPiezaEnPosicion(cursor.getPosicion()));
			else actualizarPanelStats(panelStatsROJO, nullptr);
        }
        else {
            if (bandoPiezaEnCursor == Bando::AZUL) actualizarPanelStats(panelStatsAZUL, listaPiezas.getPiezaEnPosicion(cursor.getPosicion()));
			else actualizarPanelStats(panelStatsAZUL, nullptr);
		}
    }
}

void Tablero::seleccionarPiezasConCursor()
{

    if (!hayOrigenSeleccionado) {

        Pieza* piezaSeleccionada = listaPiezas.getPiezaEnPosicion(cursor.getPosicion());

        if (piezaSeleccionada == nullptr) return;
		if (piezaSeleccionada->getBando() != turnoActual) return; //solo puedo seleccionar una pieza de mi turno
        if (piezaSeleccionada->estaEncarcelada()) return; //no puedo seleccionar una pieza encarcelada

        origenSeleccionado = cursor.getPosicion();
        hayOrigenSeleccionado = true;

        if (turnoActual == Bando::AZUL) {
            actualizarPanelStats(panelStatsAZUL, listaPiezas.getPiezaEnPosicion(origenSeleccionado));
        }
        else {
            actualizarPanelStats(panelStatsROJO, listaPiezas.getPiezaEnPosicion(origenSeleccionado));
        }

		resaltarMovimientoPosible();//actualizamos los movimientos posibles para el origen seleccionado, para luego mostrarlos en la parte gráfica

        return;
    }

	

    moverPieza(origenSeleccionado, cursor.getPosicion());
    

    hayOrigenSeleccionado = false;
	origenSeleccionado = { -1, -1 };//reiniciamos el origen seleccionado para evitar errores

	limpiarResaltados();//limpiamos los movimientos posibles para que no se sigan mostrando después de mover

    return;
}


bool Tablero::posicionValida(PosicionMatriz pos) const
{
    int fila = pos.fila;
    int col = pos.columna;
    return fila >= 0 && fila < TAM_TABLERO && col >= 0 && col < TAM_TABLERO;
}
// ----------------- FUNCIONES DEL CURSOR ----------------- END





// ----------------- FUNCIONES DE HECHIZOS ----------------- START
//void Tablero::seleccionar0CasillaHechizos()
//{
//    if (hechizoSeleccionado.cambiarCiclo) {
//        Hechizos::cambiarCiclo(ciclo);
//    }
//    limpiarHechizoSeleccionado();
//
//    vamosUsarHechizo = false;
//    cambiarTurno();
//    return;
//}

void Tablero::seleccionar1CasillaHechizos()
{
    Pieza* piezaSeleccionada = listaPiezas.getPiezaEnPosicion(cursor.getPosicion());

    if (hechizoSeleccionado.curar) {
        if (piezaSeleccionada == nullptr) return; //hechizo de curar solo se puede aplicar sobre una pieza
        if (piezaSeleccionada->getBando() != turnoActual) return; //solo puedo curar una pieza de mi bando

        Hechizos::curar(*piezaSeleccionada);
    }
    else if (hechizoSeleccionado.encarcelar) {
        if (piezaSeleccionada == nullptr) return; //hechizo de encarcelar solo se puede aplicar sobre una pieza
        if (piezaSeleccionada->getBando() == turnoActual) return; //solo puedo encarcelar una pieza del bando contrario

        Hechizos::encarcelar(listaPiezas, *piezaSeleccionada);
    }
    else if (hechizoSeleccionado.vasoDeAgua) {
        if (piezaSeleccionada == nullptr) return; //hechizo de vasoDeAgua solo se puede aplicar sobre una pieza
        if (piezaSeleccionada->getBando() == turnoActual) return; //solo puedo usar vasoDeAgua sobre una pieza del bando contrario

        Hechizos::vasoDeAgua(*piezaSeleccionada);
    }

    aplicarDebuffPorUsoHechizo();
    vamosUsarHechizo = false;
    limpiarHechizoSeleccionado();
    cambiarTurno();



    return;
}

void Tablero::seleccionar2CasillasHechizos()
{
    Pieza* piezaSeleccionada = listaPiezas.getPiezaEnPosicion(cursor.getPosicion());

    if (!hayPrimeraCasillaHechizo) {

        if (piezaSeleccionada == nullptr) return;
        if (piezaSeleccionada->getBando() != turnoActual) return; //solo puedo seleccionar una pieza de mi turno
        if (piezaSeleccionada->estaEncarcelada()) return; //no puedo seleccionar una pieza encarcelada

        primeraCasillaHechizo = cursor.getPosicion();
        hayPrimeraCasillaHechizo = true;

        return;
    }

    destinoHechizoSeleccionado = cursor.getPosicion();
    Pieza* piezaDestino = listaPiezas.getPiezaEnPosicion(destinoHechizoSeleccionado);


    if (hechizoSeleccionado.tp) {
        if (piezaDestino != nullptr) return; //la casilla de destino del tp tiene que estar vacía

        Hechizos::tp(primeraCasillaHechizo, destinoHechizoSeleccionado, listaPiezas);
    }
    else if (hechizoSeleccionado.intercambiar) {
        if (piezaDestino == nullptr) return; //la casilla de destino del intercambiar tiene que tener una pieza de mi bando
        if (piezaDestino->getBando() != turnoActual) return; //no puedo intercambiar con una pieza del bando contrario

        Hechizos::intercambiar(primeraCasillaHechizo, destinoHechizoSeleccionado, listaPiezas);
    }

    aplicarDebuffPorUsoHechizo();
    vamosUsarHechizo = false;
    limpiarHechizoSeleccionado();
    cambiarTurno();

    return;
}

void Tablero::limpiarHechizoSeleccionado()
{
    hechizoSeleccionado.tp = false;
    hechizoSeleccionado.curar = false;
    hechizoSeleccionado.cambiarCiclo = false;
    hechizoSeleccionado.intercambiar = false;
    hechizoSeleccionado.encarcelar = false;
    hechizoSeleccionado.vasoDeAgua = false;

    hayPrimeraCasillaHechizo = false;
    primeraCasillaHechizo = { -1, -1 };
    destinoHechizoSeleccionado = { -1, -1 };
}

void Tablero::aplicarDebuffPorUsoHechizo() {
    if (turnoActual == Bando::AZUL) {
        Pieza* mago = listaPiezas.getPiezaPorTipo(TipoPieza::MAGO);
        mago->setHaUsadoHechizo(true);
		mago->setDefensa(mago->getDefensa() - 0.08); 
    }
    else if (turnoActual == Bando::ROJO) {
        Pieza* hechicero = listaPiezas.getPiezaPorTipo(TipoPieza::HECHICERO);
        hechicero->setHaUsadoHechizo(true);
		hechicero->setDefensa(hechicero->getDefensa() - 0.08);
    }    
}
// ------------------ FUNCIONES DE HECHIZOS ----------------- END




// ----------------- FUNCIONES MISCELÁNEAS ----------------- START

//funcion para camiar de turno, se llama después de mover o terminar la arena
void Tablero::cambiarTurno()
{
    if (turnoActual == Bando::AZUL) {
        turnoActual = Bando::ROJO;
        cursor.setPosicion({ 4 , 8 }); //cursor en el lado de ROJO
    }
    else {
        turnoActual = Bando::AZUL;
        cursor.setPosicion({ 4 , 0 }) ; //cursor en el lado de AZUL
    }

    contadorTurnos++;
    cicloTurno();
    curaPasiva();

    if (turnoActual == Bando::AZUL) {
        actualizarPanelStats(panelStatsAZUL, listaPiezas.getPiezaEnPosicion(cursor.getPosicion()));
        actualizarPanelStats(panelStatsROJO, nullptr);
    }
    else {
        actualizarPanelStats(panelStatsAZUL, nullptr);
        actualizarPanelStats(panelStatsROJO, listaPiezas.getPiezaEnPosicion(cursor.getPosicion()));
	}
}

void Tablero::cicloTurno()
{
    for (int f = 0; f < TAM_TABLERO; f++) {
        for (int c = 0; c < TAM_TABLERO; c++) {
            casillas[f][c].cambiarOscilantes(ciclo.valor);
            Pieza* p = listaPiezas.getPiezaEnPosicion({ f,c });
            if (p != nullptr) {
                aplicarEfectoTipoCasilla(p, casillas[f][c]);
            }
        }
    }
    if (ciclo.valor) contadorTurnosParaCiclo++;
    else contadorTurnosParaCiclo--;

    if (contadorTurnosParaCiclo % 5 == 0) {
        ciclo.valor = !ciclo.valor;
    }

    switch (contadorTurnosParaCiclo) {
        case 0:
            mensajeEtapaActual = "Azul";
			break;
        case 1:
            mensajeEtapaActual = "Turquesa";
			break;
        case 2:
			mensajeEtapaActual = "Verde";
            break;
		case 3:
			mensajeEtapaActual = "Amarilla";
            break;
		case 4:
            mensajeEtapaActual = "Naranja";
			break;
        case 5:
			mensajeEtapaActual = "Roja";
            break;
    }

    for (int f = 0; f < TAM_TABLERO; f++) {
        for (int c = 0; c < TAM_TABLERO; c++) {
            Pieza* p = listaPiezas.getPiezaEnPosicion({ f,c });
            if (p != nullptr) {
                if (contadorTurnosParaCiclo == 0) {
                    if (p->estaMojada()) {
                        p->setMojada(false); //si las oscilantes son azules, (momento de AZUL) se seca y pierde los efectos de mojado
                        p->resetStats();
                    }
                    if (p->getBando() == Bando::AZUL) p->setEncarcelada(false);
                }
                if (contadorTurnosParaCiclo == 5) {
                    if (p->getBando() == Bando::ROJO) p->setEncarcelada(false);
                }
            }
        }
    }
}

//hay que limpiar el flag para que luego no se abra la arena en momentos no deseados
void Tablero::limpiarCombatePendiente()
{
    combatePendiente = false;
}

bool Tablero::resultadoCombate(Pieza* ganadorArena)
{
    Pieza* enOrigen = listaPiezas.getPiezaEnPosicion(origenCombate);
    Pieza* enDestino = listaPiezas.getPiezaEnPosicion(destinoCombate);

    if (ganadorArena) {
        Pieza* perdedor = (ganadorArena == enOrigen) ? enDestino : enOrigen;
        listaPiezas.piezaPierde(perdedor);

        if (ganadorArena == enOrigen)
            listaPiezas.moverDeCasilla(origenCombate, destinoCombate);
    }
    else {
        enOrigen->resetEstadoArena();
        enDestino->resetEstadoArena();
    }
    //enOrigen->setEnArena(false);
    //enDestino->setEnArena(false);
    bool finJuego = comprobarFinJuego();
    cambiarTurno();
    return finJuego;
}

void Tablero::actualizarPanelStats(PanelStats* panel, const Pieza* pieza)
{
	panel->setPieza(pieza);
}




Bando Tablero::comprobarCasillasDePoder()
{
	int contadorAZUL = 0;
	int contadorROJO = 0;

    for (int f = 0; f < TAM_TABLERO; f++) {
        for (int c = 0; c < TAM_TABLERO; c++) {
            if (casillas[f][c].getTipo() == TipoCasilla::PODER) {
                Pieza* p = listaPiezas.getPiezaEnPosicion({ f, c });

                if (p != nullptr) {
                    if (p->getBando() == Bando::AZUL) { contadorAZUL++;} 
                    else if (p->getBando() == Bando::ROJO) {contadorROJO++;}
                }
            }
        }
    }

    if (contadorAZUL == 5) { return Bando::AZUL; }
	else if (contadorROJO == 5) { return Bando::ROJO; }
    else return Bando::NINGUNO;
}   


bool Tablero::comprobarFinJuego()
{
    if (listaPiezas.noQuedanPiezasDeBando(Bando::AZUL)) {
		ganador = Bando::ROJO;
        return true;
    }
    else if (listaPiezas.noQuedanPiezasDeBando(Bando::ROJO)) {
        ganador = Bando::AZUL;
        return true;
    }
	else if ((ganador = comprobarCasillasDePoder()) != Bando::NINGUNO) {;
        return true;
    }
    else {
        return false;
    }
}

// ----------------- FUNCIONES MISCELÁNEAS ----------------- END






// ---------------- EFECTOS DE CASILLAS Y OTROS ----------------- START

void Tablero::aplicarEfectoTipoCasilla(Pieza* p, const Casilla& c)
{
    TipoCasilla tipo = c.getTipo();

    bool condicion = (p->estaMojada() || p->haUsadoHechizo());
    if (p->getBando() == Bando::AZUL) {
        if (tipo == TipoCasilla::AZUL) {if(!condicion) p->setDefensa(1.55);}
        else if ((tipo == TipoCasilla::TURQUESA) && !condicion) p->setDefensa(1.45);
        else if ((tipo == TipoCasilla::VERDE) && !condicion) p->setDefensa(1.25);
        else if ((tipo == TipoCasilla::AMARILLA) && !condicion) p->setDefensa(1.0);
        else if ((tipo == TipoCasilla::NARANJA) && !condicion) p->setDefensa(1.0);
        else if ((tipo == TipoCasilla::ROJA) && !condicion) p->setDefensa(1.0);
		else if (tipo == TipoCasilla::PODER) p->setDefensa(1.0);
    }
    else if (p->getBando() == Bando::ROJO) {
        if (tipo == TipoCasilla::ROJA) {if(!condicion) p->setDefensa(1.55);}
        else if ((tipo == TipoCasilla::NARANJA) && !condicion) p->setDefensa(1.45);
        else if ((tipo == TipoCasilla::AMARILLA) && !condicion) p->setDefensa(1.25);
        else if ((tipo == TipoCasilla::VERDE) && !condicion) p->setDefensa(1.0);
        else if ((tipo == TipoCasilla::TURQUESA) && !condicion) p->setDefensa(1.0);
        else if ((tipo == TipoCasilla::AZUL) && !condicion) p->setDefensa(1.0);
		else if (tipo == TipoCasilla::PODER) p->setDefensa(1.0);
    }

    //aplicar proteccion de hechizo
    if (c.getTipo() == TipoCasilla::PODER) p->setProteccionContraHechizos(true);
    else p->setProteccionContraHechizos(false);
}


void Tablero::curaPasiva()
{
    for (int f = 0; f < TAM_TABLERO; f++) {
        for (int c = 0; c < TAM_TABLERO; c++) {
            Pieza* p = listaPiezas.getPiezaEnPosicion({ f,c });
            if (p != nullptr) {
                if (casillas[f][c].getTipo() == TipoCasilla::PODER) p->curar(10.0);
                else p->curar(2.5);
            }
        }
    }
}

// ---------------- EFECTOS DE CASILLAS Y OTROS ----------------- END





// ----------- GETTERS ----------- START

//estas dos sirven para colocar las piezas después de la arena
PosicionMatriz Tablero::getOrigenCombate() const { return origenCombate; }
PosicionMatriz Tablero::getDestinoCombate() const { return destinoCombate; }

//para saber de quién es el turno, por ejemplo para mostrar en pantalla
Bando Tablero::getTurnoActual() const {return turnoActual;}

//funcion para saber si hay que cambiar a arena, obtenemos el flag de combate pendiente, para usarla en JUEGO.CPP 
bool Tablero::hayCombatePendiente() const {return combatePendiente;}

// ----------- GETTERS ----------- END
