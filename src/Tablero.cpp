#include "Tablero.h"
#include "Renderer.h"
#include <iostream>
#include "Graftablero.h"


using enum TipoCasilla;

Tablero::Tablero(double longit):
	longitud(longit), estadoTablero(EstadoTablero::TABLERO),
	turnoActual(Bando::LUZ),
	ganador(Bando::NINGUNO),
	combatePendiente(false),
	hayOrigenSeleccionado(false),
	contadorTurnos(0),
	cicloLuz_A_Oscuridad(true),
    menuHechizosLuz({ "SALIR","TP","CURAR","TIEMPO","SWITCH","CARCEL","TIJ" },
        { MenuAccion::SALIR, MenuAccion::TP, MenuAccion::CURAR, MenuAccion::CAMBIAR_TIEMPO, MenuAccion::INTERCAMBIAR, MenuAccion::ENCARCELAR, MenuAccion::TIJERAS },
        { (Config::sizeMundo.x - Config::sizeMundo.y) * 0.5, Config::sizeMundo.y },
        { (Config::sizeMundo.x - Config::sizeMundo.y) * 0.5 * 0.5, Config::sizeMundo.y * 0.5 }, "LUZ", { 1.0f, 0.0f, 0.0f }),

    menuHechizosOscuridad({ "SALIR","TP","CURAR","TIEMPO","SWITCH","CARCEL","TIJ" },
        { MenuAccion::SALIR, MenuAccion::TP, MenuAccion::CURAR, MenuAccion::CAMBIAR_TIEMPO, MenuAccion::INTERCAMBIAR, MenuAccion::ENCARCELAR, MenuAccion::TIJERAS },
        { (Config::sizeMundo.x - Config::sizeMundo.y) * 0.5, Config::sizeMundo.y },
        { (Config::sizeMundo.x - Config::sizeMundo.y) * 0.5 * 0.5, Config::sizeMundo.y * 0.5 }, "OSC", { 0.0f, 1.0f, 0.0f })
{
}


void Tablero::inicializa()
{
	estadoTablero = EstadoTablero::TABLERO;

	menuHechizosLuz.inicializa();
	menuHechizosOscuridad.inicializa();

	ganador = Bando::NINGUNO;
    turnoActual = Bando::LUZ;

	combatePendiente = false;
    hayOrigenSeleccionado = false;

	//INICIALIZA CASILLAS
    constexpr TipoCasilla tipoCasillas[TAM][TAM] =
    {
     { OSCURA,     CLARA,     OSCURA,     OSCILANTE,  PODER,      OSCILANTE,  OSCURA,     CLARA,     OSCURA     },
     { CLARA,      OSCURA,    OSCILANTE,  CLARA,      OSCILANTE,  CLARA,      OSCILANTE,  OSCURA,    CLARA      },
     { OSCURA,     OSCILANTE, CLARA,      OSCURA,     OSCILANTE,  OSCURA,     CLARA,      OSCILANTE, OSCURA     },
     { OSCILANTE,  CLARA,     OSCURA,     CLARA,      OSCILANTE,  CLARA,      OSCURA,     CLARA,     OSCILANTE  },
     { PODER,      OSCILANTE, OSCILANTE,  OSCILANTE,  PODER,      OSCILANTE,  OSCILANTE,  OSCILANTE, PODER      },
     { OSCILANTE,  CLARA,     OSCURA,     CLARA,      OSCILANTE,  CLARA,      OSCURA,     CLARA,     OSCILANTE  },
     { OSCURA,     OSCILANTE, CLARA,      OSCURA,     OSCILANTE,  OSCURA,     CLARA,      OSCILANTE, OSCURA     },
     { CLARA,      OSCURA,    OSCILANTE,  CLARA,      OSCILANTE,  CLARA,      OSCILANTE,  OSCURA,    CLARA      },
     { OSCURA,     CLARA,     OSCURA,     OSCILANTE,  PODER,      OSCILANTE,  OSCURA,     CLARA,     OSCURA     }
    };
    for (int f = 0; f < TAM; f++) {
        for (int c = 0; c < TAM; c++) {
            casillas[f][c].inicializa(tipoCasillas[f][c], { f, c });
        }
    }

    //INICIALIZA CASILLAS


    // ------------- INICIALIZA PIEZAS --------- PONER SU POSICION INICIAL
    // ------COLUMNA 0
    agregarPieza<Valquiria>(0, 0);
    agregarPieza<Golem>(1, 0);
    agregarPieza<Unicornio>(2, 0);
    agregarPieza<Djinni>(3, 0);
    agregarPieza<Mago>(4, 0);
    agregarPieza<Fenix>(5, 0);
    agregarPieza<Unicornio>(6, 0);
    agregarPieza<Golem>(7, 0);
    agregarPieza<Valquiria>(8, 0);


    //------COLUMNA 1
    agregarPieza<Arquero>(0, 1);
    agregarPieza<Caballero>(1, 1);
    agregarPieza<Caballero>(2, 1);
    agregarPieza<Caballero>(3, 1);
    agregarPieza<Caballero>(4, 1);
    agregarPieza<Caballero>(5, 1);
    agregarPieza<Caballero>(6, 1);
    agregarPieza<Caballero>(7, 1);
    agregarPieza<Arquero>(8, 1);


    //------COLUMNA 7
    agregarPieza<Manticora>(0, 7);
    agregarPieza<Duende>(1, 7);
    agregarPieza<Duende>(2, 7);
    agregarPieza<Duende>(3, 7);
    agregarPieza<Duende>(4, 7);
    agregarPieza<Duende>(5, 7);
    agregarPieza<Duende>(6, 7);
    agregarPieza<Duende>(7, 7);
    agregarPieza<Manticora>(8, 7);


    // ------COLUMNA 8
    agregarPieza<Banshee>(0, 8);
    agregarPieza<Trol>(1, 8);
    agregarPieza<Basilisco>(2, 8);
    agregarPieza<Cambiaforma>(3, 8);
    agregarPieza<Hechicero>(4, 8);
    agregarPieza<Dragon>(5, 8);
    agregarPieza<Basilisco>(6, 8);
    agregarPieza<Trol>(7, 8);
    agregarPieza<Banshee>(8, 8);




    panelStatsLuz = new PanelStats{
        {Config::sizeMundo.x * 0.12, Config::sizeMundo.y * 0.42},
        { posicion.x + longitud / 1.975, posicion.y - longitud/2.2},
        colorFondoPanel, colorTextoPanel, colorTituloPanelLuz, colorBordePanel, "Luz", static_cast<int>(Config::sizeMundo.x * 0.02), static_cast<int>(Config::sizeMundo.x * 0.02)
    };

    panelStatsOscuridad = new PanelStats{
        {Config::sizeMundo.x * 0.12, Config::sizeMundo.y * 0.42},
        { posicion.x + longitud / 1.975, posicion.y - longitud / 2.5 + Config::sizeMundo.y * 0.42},
        colorFondoPanel, colorTextoPanel, colorTituloPanelOscuridad, colorBordePanel, "Oscuridad", static_cast<int>(Config::sizeMundo.x * 0.02), static_cast<int>(Config::sizeMundo.x * 0.02)
    };

	//inicializo panel de stats con la pieza que está debajo del cursor al inicio
	if (turnoActual == Bando::LUZ) actualizarPanelStats(panelStatsLuz, listaPiezas.getPiezaEnPosicion(cursor.getPosicion()));
    else actualizarPanelStats(panelStatsOscuridad, listaPiezas.getPiezaEnPosicion(cursor.getPosicion()));
}

// --------------- FUNCIONES DE DIBUJO ------------------ START
void Tablero::dibuja(const Renderer& renderer)const {
    renderer.dibujaSprite(mesa.sprite, posicion, Config::sizeMundo.x, Config::sizeMundo.y);
    renderer.dibujaSprite(hoja.sprite, posicion, Config::sizeMundo.x * 0.6, Config::sizeMundo.y * 0.8);

    double longitudCasilla = longitud / TAM;
    Vector2D esquinaSuperiorIzda{ posicion.x - longitud / 2.0, posicion.y - longitud / 2.0 };
    for (unsigned int f = 0; f < TAM; f++) {
        for (unsigned int c = 0; c < TAM; c++) {
            Vector2D centroCasilla{ esquinaSuperiorIzda.x + (c + 0.5) * longitudCasilla, esquinaSuperiorIzda.y + (f + 0.5) * longitudCasilla };
             casillas[f][c].dibuja(renderer, centroCasilla, longitudCasilla);
        }
    }

    
	listaPiezas.dibujarPiezas(renderer, esquinaSuperiorIzda, longitudCasilla);
    dibujaOrigenSeleccionado(renderer, esquinaSuperiorIzda, longitudCasilla);
    cursor.dibuja(renderer, esquinaSuperiorIzda, longitudCasilla, turnoActual);

	if (estadoTablero == EstadoTablero::MENU_HECHIZOS && turnoActual == Bando::LUZ) {
		menuHechizosLuz.dibuja(renderer);
	}
	else if (estadoTablero == EstadoTablero::MENU_HECHIZOS && turnoActual == Bando::OSCURIDAD) {
		menuHechizosOscuridad.dibuja(renderer);
	}

	panelStatsLuz->dibuja(renderer);
	panelStatsOscuridad->dibuja(renderer);
}



void Tablero::resaltarMovimientoPosible()
{

    limpiarResaltados();

    if (!hayOrigenSeleccionado) {
        return;
    }

    for (int f = 0; f < TAM; f++) {
        for (int c = 0; c < TAM; c++) {
            PosicionMatriz destino_posible{ f,c };

            if (movimientoLegal(origenSeleccionado, destino_posible)) {
                movimientosPosibles.push_back(destino_posible);
                casillas[f][c].setResaltada(true);
            }
        }
    }
}

void Tablero::limpiarResaltados() {
    for (int f = 0; f < TAM; f++) {
        for (int c = 0; c < TAM; c++) {
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
    if (defensor != nullptr && defensor->getBando() != Bando::NINGUNO) {
		aplicarEfectoTipoCasilla(atacante, casillas[destino.fila][destino.columna]); 
        //Se actualizan los valores antes de entrar a la arena, ya que pelean en la casilla destino y esa es la que aplica.
		//haciendo que si el atacante gana, se queda con la misma defensa con la que entraba (la de destino) y si el defensor gana se queda con la misma ya que no se mueve de casilla.

        combatePendiente = true; //FLAG PARA CAMBIAR A ARENA
        origenCombate = origen;
        destinoCombate = destino;

        return true;
    }

    //Movimiento normal
	listaPiezas.moverDeCasilla(origen, destino);
    aplicarEfectoTipoCasilla(listaPiezas.getPiezaEnPosicion(destino), casillas[destino.fila][destino.columna]); //para que se actualicen los valores de defensa y poder verlos en tiempo real, a efectos prácticos solo necesitamos aplicarlos antes de arena

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
            seleccionarPiezasConCursor();
            if (comprobarFinJuego()) {
                return  TableroAccion::IR_FIN_PARTIDA;
            }
            //tablero avisa de que se he elegido combate, haciendo que juego ponga el estado ARENA y limpiando el flag del combate pendiente para no volver a entrar 
            else if (hayCombatePendiente()) {
                limpiarCombatePendiente();
                return TableroAccion::IR_ARENA;
            }
            break;
        }
        //case '\x1B': case 'P': case 'p':// '\x1B'==ESC
        //    return  TableroAccion::IR_PAUSA;

        case 'h':
        {
            estadoTablero = EstadoTablero::MENU_HECHIZOS;
            break;
        }
        case'f':
            return TableroAccion::IR_FIN_PARTIDA;
        default:
            return TableroAccion::NINGUNA;
        }
        break;
    }
    case EstadoTablero::MENU_HECHIZOS:
    {
        MenuAccion accion= MenuAccion::NINGUNA;
        if (turnoActual == Bando::LUZ)
            accion = menuHechizosLuz.tecla(key);
		else if (turnoActual == Bando::OSCURIDAD)
            accion = menuHechizosOscuridad.tecla(key);
        switch (accion)
        {
        case MenuAccion::TP:
        case MenuAccion::CURAR:
        case MenuAccion::CAMBIAR_TIEMPO:
        case MenuAccion::INTERCAMBIAR:
        case MenuAccion::ENCARCELAR:
        case MenuAccion::TIJERAS:
        {
            estadoTablero = EstadoTablero::TABLERO; //PROVISIONAL
            break;
        }
        case MenuAccion::SALIR:
        {
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

// MOSTRAR STATS DE LA PIEZA EN LA QUE TENGO EL CURSOR!!!!!!!!!
void Tablero::moverCursor(int df, int dc)
{
	PosicionMatriz nuevaPosicion = { cursor.getPosicion().fila + df, cursor.getPosicion().columna + dc };

    if (posicionValida(nuevaPosicion)) cursor.mover(df, dc);
    
	Pieza* piezaEnCursor = listaPiezas.getPiezaEnPosicion(cursor.getPosicion());
	Bando bandoPiezaEnCursor = (piezaEnCursor != nullptr) ? piezaEnCursor->getBando() : Bando::NINGUNO;

    if (!hayOrigenSeleccionado) {
         if (bandoPiezaEnCursor == Bando::LUZ) {
             actualizarPanelStats(panelStatsLuz, listaPiezas.getPiezaEnPosicion(cursor.getPosicion()));
             actualizarPanelStats(panelStatsOscuridad, nullptr);
         }
         else if (bandoPiezaEnCursor == Bando::OSCURIDAD) {
             actualizarPanelStats(panelStatsLuz, nullptr);
             actualizarPanelStats(panelStatsOscuridad, listaPiezas.getPiezaEnPosicion(cursor.getPosicion()));
         }
         else {
             actualizarPanelStats(panelStatsOscuridad, nullptr);
			 actualizarPanelStats(panelStatsLuz, nullptr);
         }
    }
    else {
        if (turnoActual == Bando::LUZ) {
            actualizarPanelStats(panelStatsOscuridad, listaPiezas.getPiezaEnPosicion(cursor.getPosicion()));
        }
        else {
            actualizarPanelStats(panelStatsLuz, listaPiezas.getPiezaEnPosicion(cursor.getPosicion()));
		}
    }
}

bool Tablero::seleccionarPiezasConCursor()
{

    if (!hayOrigenSeleccionado) {

        Pieza* piezaSeleccionada = listaPiezas.getPiezaEnPosicion(cursor.getPosicion());

        if (piezaSeleccionada == nullptr) return false;
		if (piezaSeleccionada->getBando() != turnoActual) return false; //solo puedo seleccionar una pieza de mi turno

        origenSeleccionado = cursor.getPosicion();
        hayOrigenSeleccionado = true;

        if (turnoActual == Bando::LUZ) {
            actualizarPanelStats(panelStatsLuz, listaPiezas.getPiezaEnPosicion(origenSeleccionado));
        }
        else {
            actualizarPanelStats(panelStatsOscuridad, listaPiezas.getPiezaEnPosicion(origenSeleccionado));
        }

		resaltarMovimientoPosible();//actualizamos los movimientos posibles para el origen seleccionado, para luego mostrarlos en la parte gráfica

        return true;
    }

	

    bool movimientoCorrecto = moverPieza(origenSeleccionado, cursor.getPosicion());
    

    hayOrigenSeleccionado = false;
	origenSeleccionado = { -1, -1 };//reiniciamos el origen seleccionado para evitar errores

	limpiarResaltados();//limpiamos los movimientos posibles para que no se sigan mostrando después de mover

    return movimientoCorrecto;
}


bool Tablero::posicionValida(PosicionMatriz pos) const
{
    int fila = pos.fila;
    int col = pos.columna;
    return fila >= 0 && fila < TAM && col >= 0 && col < TAM;
}
// ----------------- FUNCIONES DEL CURSOR ----------------- END







// ----------------- FUNCIONES MISCELÁNEAS ----------------- START

//funcion para camiar de turno, se llama después de mover o terminar la arena
void Tablero::cambiarTurno()
{
    //quitar entre estos coments 
    static int llamada = 0;
    printf("[cambiarTurno #%d] antes=%s\n", ++llamada, turnoActual == Bando::LUZ ? "LUZ" : "OSC");
//quitar  
    if (turnoActual == Bando::LUZ) {
        turnoActual = Bando::OSCURIDAD;
        cursor.setPosicion({ 4 , 8 }); //cursor en el lado de oscuridad
    }
    else {
        turnoActual = Bando::LUZ;
        cursor.setPosicion({ 4 , 0 }) ; //cursor en el lado de luz
    }
    //
    printf("[cambiarTurno #%d] despues=%s\n", llamada, turnoActual == Bando::LUZ ? "LUZ" : "OSC");
    //
    cicloTurno();
    curaPasiva();

    if (turnoActual == Bando::LUZ) {
        actualizarPanelStats(panelStatsLuz, listaPiezas.getPiezaEnPosicion(cursor.getPosicion()));
        actualizarPanelStats(panelStatsOscuridad, nullptr);
    }
    else {
        actualizarPanelStats(panelStatsLuz, nullptr);
        actualizarPanelStats(panelStatsOscuridad, listaPiezas.getPiezaEnPosicion(cursor.getPosicion()));
	}
}

void Tablero::cicloTurno()
{
    for (int f = 0; f < TAM; f++) {
        for (int c = 0; c < TAM; c++) {
            casillas[f][c].cambiarOscilantes(cicloLuz_A_Oscuridad);
        }
    }

    for (int f = 0; f < TAM; f++) {
        for (int c = 0; c < TAM; c++) {
            Pieza* p = listaPiezas.getPiezaEnPosicion({ f,c });
            if (p != nullptr) {
                aplicarEfectoTipoCasilla(p, casillas[f][c]);
            }
        }
	}

    contadorTurnos++;

    if (contadorTurnos % 5 == 0) {
        cicloLuz_A_Oscuridad = !cicloLuz_A_Oscuridad; 
    }   
}

//hay que limpiar el flag para que luego no se abra la arena en momentos no deseados
void Tablero::limpiarCombatePendiente()
{
    combatePendiente = false;
}
void Tablero::resultadoCombate(Pieza* ganador)
{
    Pieza* enOrigen = listaPiezas.getPiezaEnPosicion(origenCombate);
    Pieza* enDestino = listaPiezas.getPiezaEnPosicion(destinoCombate);

    if (ganador) {
        Pieza* perdedor = (ganador == enOrigen) ? enDestino : enOrigen;
        if (perdedor) listaPiezas.piezaPierde(perdedor);

        if (ganador == enOrigen)
            listaPiezas.moverDeCasilla(origenCombate, destinoCombate);
    }

    if (enOrigen) enOrigen->resetEstadoArena();
    if (enDestino) enDestino->resetEstadoArena();
   
    cambiarTurno();
}

void Tablero::actualizarPanelStats(PanelStats* panel, const Pieza* pieza)
{
	panel->setPieza(pieza);
}




Bando Tablero::comprobarCasillasDePoder()
{
	int contadorLuz = 0;
	int contadorOscuridad = 0;

    for (int f = 0; f < TAM; f++) {
        for (int c = 0; c < TAM; c++) {
            if (casillas[f][c].getTipo() == TipoCasilla::PODER) {
                Pieza* p = listaPiezas.getPiezaEnPosicion({ f, c });

                if (p != nullptr) {
                    if (p->getBando() == Bando::LUZ) { contadorLuz++;} 
                    else if (p->getBando() == Bando::OSCURIDAD) {contadorOscuridad++;}
                }
            }
        }
    }

    if (contadorLuz == 5) { return Bando::LUZ; }
	else if (contadorOscuridad == 5) { return Bando::OSCURIDAD; }
    else return Bando::NINGUNO;
}   


bool Tablero::comprobarFinJuego()
{
    if (listaPiezas.noQuedanPiezasDeBando(Bando::LUZ)) {
		ganador = Bando::OSCURIDAD;
        return true;
    }
    else if (listaPiezas.noQuedanPiezasDeBando(Bando::OSCURIDAD)) {
        ganador = Bando::LUZ;
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

    if (p->getBando() == Bando::LUZ) {
        if (tipo == TipoCasilla::CLARA) p->setDefensa(1.55);
        else if (tipo == TipoCasilla::BASTANTE_CLARA) p->setDefensa(1.45);
        else if (tipo == TipoCasilla::LIGERAMENTE_CLARA) p->setDefensa(1.25);
        else if (tipo == TipoCasilla::LIGERAMENTE_OSCURA) p->setDefensa(1.0);
        else if (tipo == TipoCasilla::BASTANTE_OSCURA) p->setDefensa(1.0);
        else if (tipo == TipoCasilla::OSCURA) p->setDefensa(1.0);
    }
    else if (p->getBando() == Bando::OSCURIDAD) {
        if (tipo == TipoCasilla::OSCURA) p->setDefensa(1.5);
        else if (tipo == TipoCasilla::BASTANTE_OSCURA) p->setDefensa(1.45);
        else if (tipo == TipoCasilla::LIGERAMENTE_OSCURA) p->setDefensa(1.25);
        else if (tipo == TipoCasilla::LIGERAMENTE_CLARA) p->setDefensa(1.0);
        else if (tipo == TipoCasilla::BASTANTE_CLARA) p->setDefensa(1.0);
        else if (tipo == TipoCasilla::CLARA) p->setDefensa(1.0);
    }

    //aplicar proteccion de hechizo
    if (c.getTipo() == TipoCasilla::PODER) p->setProteccionContraHechizos(true);
    else p->setProteccionContraHechizos(false);
}


void Tablero::curaPasiva()
{
    for (int f = 0; f < TAM; f++) {
        for (int c = 0; c < TAM; c++) {
            Pieza* p = listaPiezas.getPiezaEnPosicion({ f,c });
            if (p != nullptr) {
                if (casillas[f][c].getTipo() == TipoCasilla::PODER) p->curar(10.0);
                else p->curar(5.0);
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

PosicionMatriz Tablero::getOrigenSeleccionado() const { return origenSeleccionado; }
bool Tablero::getHayOrigenSeleccionado() const {return hayOrigenSeleccionado;}

// ----------- GETTERS ----------- END
