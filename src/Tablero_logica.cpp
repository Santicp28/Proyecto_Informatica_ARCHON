#include "Tablero_logica.h"
#include "Renderer.h"
#include <algorithm>
#include <iostream>


using enum TipoCasilla;

void Tablero_logica::inicializa()
{


    turnoActual = Bando::LUZ;
    cursor = { 5, 0 };

    combatePendiente = false;
    hayOrigenSeleccionado = false;
    longitud = std::min(Config::sizeMundo.x, Config::sizeMundo.y);

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
}


void Tablero_logica::dibuja(const Renderer& renderer)const {
    double longitudCasilla = longitud / TAM;
    Vector2D esquinaSuperiorIzda{ posicion.x - longitud / 2.0, posicion.y - longitud / 2.0 };

    for (unsigned int f = 0; f < TAM; f++) {
        for (unsigned int c = 0; c < TAM; c++) {
            Vector2D centroCasilla{ esquinaSuperiorIzda.x + (c + 0.5) * longitudCasilla, esquinaSuperiorIzda.y + (f + 0.5) * longitudCasilla };
             casillas[f][c].dibuja(renderer, centroCasilla, longitudCasilla);
        }
    }

	listaPiezas.dibujarPiezas(renderer, esquinaSuperiorIzda, longitudCasilla);


}


// --------------- LOGICA DE MOVIMIENTO ------------------ START

bool Tablero_logica::mover(PosicionMatriz origen, PosicionMatriz destino) 
{
    if (!movimientoLegal(origen, destino)) return false;
        
    Pieza* atacante = listaPiezas.getPiezaEnPosicion(origen);
    Pieza* defensor = listaPiezas.getPiezaEnPosicion(destino);

    //ILUMINAR O DESTACAR CASILLA SI HAY ERROR O MOSTRAR UN SONIDO O ALGO, TAMBIEN MOSTRAR MENSAJE PARA SABER EL ERROR

    //Si hay enemigo, no movemos todavía
    //Dejamos marcado que tiene que abrirse la arena
    if (defensor->getBando() != Bando::NINGUNO) {
        combatePendiente = true; //FLAG PARA CAMBIAR A ARENA
        origenCombate = origen;
        destinoCombate = destino;

        return true;
    }

    //Movimiento normal
	listaPiezas.moverDeCasilla(origen, destino);
    cambiarTurno();

    return true;
}


bool Tablero_logica::movimientoLegal(PosicionMatriz origen, PosicionMatriz destino) const
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


bool Tablero_logica::caminoLibreEnL(PosicionMatriz origen, PosicionMatriz destino, bool primeroFilas) const //primero avanza por filas y luego por columnas para comprobar el camino en L, para comprobar las distintas posibilidades de camino. Se llama 2 veces.
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






// ----------------- FUNCIONES DEL CURSOR ----------------- START

// MOSTRAR STATS DE LA PIEZA EN LA QUE TENGO EL CURSOR!!!!!!!!!

//comprueba si se puede mover y luego asigna la nueva posicion al cursor, se llama desde juego cuando se pulsa una flecha
void Tablero_logica::moverCursor(int df, int dc)
{
	PosicionMatriz nuevaPosicion{ cursor.fila + df, cursor.columna + dc };

    if (interaccion.posicionValida(nuevaPosicion)) cursor = nuevaPosicion;
}


bool Tablero_logica::seleccionarConCursor()
{

    if (!hayOrigenSeleccionado) {
		if (interaccion.getBandoOcupante(cursor, listaPiezas) != turnoActual) return false; //solo puedo seleccionar una pieza de mi turno

        origenSeleccionado = cursor;
        hayOrigenSeleccionado = true;

		resaltarMovimientoPosible();//actualizamos los movimientos posibles para el origen seleccionado, para luego mostrarlos en la parte gráfica

        return true;
    }

    bool movimientoCorrecto = mover(origenSeleccionado, cursor);

    hayOrigenSeleccionado = false;
	origenSeleccionado = { -1, -1 };//reiniciamos el origen seleccionado para evitar errores

	movimientosPosibles.clear();//limpiamos los movimientos posibles para que no se sigan mostrando después de mover

    return movimientoCorrecto;
}

void Tablero_logica::resaltarMovimientoPosible()
{
    movimientosPosibles.clear();

    if (!hayOrigenSeleccionado) {
        return;
    }

    for (int f = 0; f < TAM; f++) {
        for (int c = 0; c < TAM; c++) {
            PosicionMatriz destino_posible{f,c};

            if (movimientoLegal(origenSeleccionado, destino_posible)) {
                movimientosPosibles.push_back(destino_posible);
            }
        }
    }
}


// ----------------- FUNCIONES DEL CURSOR ----------------- END





// ----------------- FUNCIONES MISCELÁNEAS ----------------- START

//funcion para camiar de turno, se llama después de mover o terminar la arena
void Tablero_logica::cambiarTurno()
{
    if (turnoActual == Bando::LUZ) {
        turnoActual = Bando::OSCURIDAD;
        cursor = { 4 , 8 }; //cursor en el lado de oscuridad
    }
    else {
        turnoActual = Bando::LUZ;
        cursor = { 4 , 0 }; //cursor en el lado de luz
    }
}

//hay que limpiar el flag para que luego no se abra la arena en momentos no deseados
void Tablero_logica::limpiarCombatePendiente()
{
    combatePendiente = false;
}

// ----------------- FUNCIONES DE MISCELÁNEAS ----------------- END




// ----------- GETTERS ----------- START

//estas dos sirven para colocar las piezas después de la arena
PosicionMatriz Tablero_logica::getOrigenCombate() const { return origenCombate; }
PosicionMatriz Tablero_logica::getDestinoCombate() const { return destinoCombate; }

//para saber de quién es el turno, por ejemplo para mostrar en pantalla
Bando Tablero_logica::getTurnoActual() const {return turnoActual;}

//funcion para saber si hay que cambiar a arena, obtenemos el flag de combate pendiente, para usarla en JUEGO.CPP 
bool Tablero_logica::hayCombatePendiente() const {return combatePendiente;}

PosicionMatriz Tablero_logica::getCursor() const {return cursor;}

PosicionMatriz Tablero_logica::getOrigenSeleccionado() const { return origenSeleccionado; }
bool Tablero_logica::getHayOrigenSeleccionado() const {return hayOrigenSeleccionado;}

// ----------- GETTERS ----------- END