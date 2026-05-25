#include "Tablero_logica.h"
#include "Renderer.h"
#include <iostream>


using enum TipoCasilla;

void Tablero_logica::inicializa()
{


    turnoActual = Bando::LUZ;
    cursor = { 5, 0 };

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
    Pieza* valq1 = new Valquiria();
    valq1->setPosicionMatriz(0, 0);

    Pieza* golem1 = new Golem();
    golem1->setPosicionMatriz(1, 0);

    Pieza* unic1 = new Unicornio();
    unic1->setPosicionMatriz(2, 0);

    Pieza* djin1 = new Djinni();
    djin1->setPosicionMatriz(3, 0);

    Pieza* mago1 = new Mago();
    mago1->setPosicionMatriz(4, 0);

    Pieza* fenix1 = new Fenix();
    fenix1->setPosicionMatriz(5, 0);

    Pieza* unic2 = new Unicornio();
    unic2->setPosicionMatriz(6, 0);

    Pieza* golem2 = new Golem();
    golem2->setPosicionMatriz(7, 0);

    Pieza* valq2 = new Valquiria();
    valq2->setPosicionMatriz(8, 0);

    listaPiezas.agregar(valq1);
    listaPiezas.agregar(golem1);
    listaPiezas.agregar(unic1);
    listaPiezas.agregar(djin1);
    listaPiezas.agregar(mago1);
    listaPiezas.agregar(fenix1);
    listaPiezas.agregar(unic2);
    listaPiezas.agregar(golem2);
    listaPiezas.agregar(valq2);


    //------COLUMNA 1
    Pieza* arq1 = new Arquero();
    arq1->setPosicionMatriz(0, 1);

    Pieza* cab1 = new Caballero();
    cab1->setPosicionMatriz(1, 1);

    Pieza* cab2 = new Caballero();
    cab2->setPosicionMatriz(2, 1);

    Pieza* cab3 = new Caballero();
    cab3->setPosicionMatriz(3, 1);

    Pieza* cab4 = new Caballero();
    cab4->setPosicionMatriz(4, 1);

    Pieza* cab5 = new Caballero();
    cab5->setPosicionMatriz(5, 1);

    Pieza* cab6 = new Caballero();
    cab6->setPosicionMatriz(6, 1);

    Pieza* cab7 = new Caballero();
    cab7->setPosicionMatriz(7, 1);

    Pieza* arq2 = new Arquero();
    arq2->setPosicionMatriz(8, 1);

    listaPiezas.agregar(arq1);
    listaPiezas.agregar(cab1);
    listaPiezas.agregar(cab2);
    listaPiezas.agregar(cab3);
    listaPiezas.agregar(cab4);
    listaPiezas.agregar(cab5);
    listaPiezas.agregar(cab6);
    listaPiezas.agregar(cab7);
    listaPiezas.agregar(arq2);

    //------COLUMNA 7
    Pieza* mant1 = new Manticora();
    mant1->setPosicionMatriz(0, 7);

    Pieza* gob1 = new Duende();
    gob1->setPosicionMatriz(1, 7);

    Pieza* gob2 = new Duende();
    gob2->setPosicionMatriz(2, 7);

    Pieza* gob3 = new Duende();
    gob3->setPosicionMatriz(3, 7);

    Pieza* gob4 = new Duende();
    gob4->setPosicionMatriz(4, 7);

    Pieza* gob5 = new Duende();
    gob5->setPosicionMatriz(5, 7);

    Pieza* gob6 = new Duende();
    gob6->setPosicionMatriz(6, 7);

    Pieza* gob7 = new Duende();
    gob7->setPosicionMatriz(7, 7);

    Pieza* mant2 = new Manticora();
    mant2->setPosicionMatriz(8, 7);

    listaPiezas.agregar(mant1);
    listaPiezas.agregar(gob1);
    listaPiezas.agregar(gob2);
    listaPiezas.agregar(gob3);
    listaPiezas.agregar(gob4);
    listaPiezas.agregar(gob5);
    listaPiezas.agregar(gob6);
    listaPiezas.agregar(gob7);
    listaPiezas.agregar(mant2);

    //------COLUMNA 8
    Pieza* bansh1 = new Banshee();
    bansh1->setPosicionMatriz(0, 8);

    Pieza* trol1 = new Trol();
    trol1->setPosicionMatriz(1, 8);

    Pieza* basi1 = new Basilisco();
    basi1->setPosicionMatriz(2, 8);

    Pieza* camb1 = new Cambiaforma();
    camb1->setPosicionMatriz(3, 8);

    Pieza* hech1 = new Hechicero();
    hech1->setPosicionMatriz(4, 8);

    Pieza* dragon1 = new Dragon();
    dragon1->setPosicionMatriz(5, 8);

    Pieza* basi2 = new Basilisco();
    basi2->setPosicionMatriz(6, 8);

    Pieza* trol2 = new Trol();
    trol2->setPosicionMatriz(7, 8);

    Pieza* bansh2 = new Banshee();
    bansh2->setPosicionMatriz(8, 8);

    listaPiezas.agregar(bansh1);
    listaPiezas.agregar(trol1);
    listaPiezas.agregar(basi1);
    listaPiezas.agregar(camb1);
    listaPiezas.agregar(hech1);
    listaPiezas.agregar(dragon1);
    listaPiezas.agregar(basi2);
    listaPiezas.agregar(trol2);
    listaPiezas.agregar(bansh2);

}


void Tablero_logica::dibuja(const Renderer& renderer)const {
    double longitudCasilla = longitud / TAM;
    Vector2D centro = renderer.obtenerSizeDibujo() * 0.5;
    Vector2D esquinaSuperiorIzda{ centro.x - longitud / 2.0, centro.y + longitud / 2.0 };

    for (unsigned int f = 0; f < TAM; f++) {
        for (unsigned int c = 0; c < TAM; c++) {
            Vector2D centroCasilla{ esquinaSuperiorIzda.x + (c + 0.5) * longitudCasilla, esquinaSuperiorIzda.y - (f + 0.5) * longitudCasilla };
            casillas[f][c].dibuja(renderer, centroCasilla, longitudCasilla);
        }
    }


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