#include "Tablero_logica.h"
#include "DesacopleGrafico.h"
#include <iostream>

using enum TipoCasilla;

void Tablero_logica::inicializa()
{


    turnoActual = Bando::LUZ;
    combatePendiente = false;
    hayOrigenSeleccionado = false;

    cursor = { 0, 0 };


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
    for (unsigned int f = 0; f < TAM; f++) {
        for (unsigned int c = 0; c < TAM; c++) {
            casillas[f][c].inicializa(tipoCasillas[f][c], { f, c });
        }
    }
    //INICIALIZA CASILLAS


    //INICIALIZA PIEZAS --------- PONER SU POSICION INICIAL
    //PIEZAS LUZ
    listaPiezas.agregar(new );
    listaPiezas.agregar(new );
    listaPiezas.agregar(new );

    //PIEZAS OSCURIDAD
    listaPiezas.agregar(new );
    listaPiezas.agregar(new );
    listaPiezas.agregar(new );
    //INICIALIZA PIEZAS

}




bool Tablero_logica::mover(Casilla origen, Casilla destino) //CADA PIEZA SE MUEVE DISTINTO
{
    if (!interaccion.posicionValida(origen, TAM)) {
        std::cout << "Movimiento invalido: origen fuera del tablero." << std::endl;
        return false;
    }

    if (!interaccion.posicionValida(destino, TAM)) {
        std::cout << "Movimiento invalido: destino fuera del tablero." << std::endl;
        return false;
    }

    Bando atacante = interaccion.getBandoOcupante(origen, listaPiezas);
    Bando defensor = interaccion.getBandoOcupante(destino, listaPiezas);

    //ILUMINAR O DESTACAR CASILLA SI HAY ERROR O MOSTRAR UN SONIDO O ALGO, TAMBIEN MOSTRAR MENSAJE PARA SABER EL ERROR
    
    //No hay pieza en origen
    if (atacante == Bando::NINGUNO) {
        std::cout << "Movimiento invalido: no hay pieza en el origen." << std::endl;
        return false;
    }

    //No es ty turno
    if (atacante != turnoActual) {
        std::cout << "Movimiento invalido: no es el turno de esa pieza." << std::endl;
        return false;
    }

	//Hay una pieza aliada en destino
    if (defensor == atacante) {
        std::cout << "Movimiento invalido: la casilla destino tiene una pieza aliada." << std::endl;
        return false;
    }

    //Si hay enemigo, no movemos todavía
    //Dejamos marcado que tiene que abrirse la arena.
    if (defensor != Bando::NINGUNO && defensor != atacante) {
        combatePendiente = true; //FLAG PARA CAMBIAR A ARENA
        origenCombate = origen.getPosicionMatriz();
        destinoCombate = destino.getPosicionMatriz();

        std::cout << "Combate pendiente entre origen (" << origenCombate.fila << ", " << origenCombate.columna
            << ") y destino (" << destinoCombate.fila << ", " << destinoCombate.columna << ")." << std::endl;

        return true;
    }

    //Movimiento normal
	listaPiezas.moverDeCasilla(origen, destino);

    std::cout << "Pieza movida correctamente de ("
        << origen.getPosicionMatriz().fila << ", " << origen.getPosicionMatriz().columna
        << ") a ("
        << destino.getPosicionMatriz().fila << ", " << destino.getPosicionMatriz().columna
        << ")." << std::endl;

    cambiarTurno();

    std::cout << "Turno cambiado." << std::endl;

    return true;
}

//funcion para saber si hay que cambiar a arena, obtenemos el flag de combate pendiente, para usarla en JUEGO.CPP 
bool Tablero_logica::hayCombatePendiente() const
{
    return combatePendiente;
}

//hay que limpiar el flag para que luego no se abra la arena en momentos no deseados
void Tablero_logica::limpiarCombatePendiente()
{
    combatePendiente = false;
}


//estas dos sirven para colocar las piezas después de la arena
PosicionMatriz Tablero_logica::getOrigenCombate() const
{
    return origenCombate;
}

PosicionMatriz Tablero_logica::getDestinoCombate() const
{
    return destinoCombate;
}



//para saber de quién es el turno, por ejemplo para mostrar en pantalla
Bando Tablero_logica::getTurnoActual() const
{
    return turnoActual;
}

//funcion para camiar de turno, se llama después de mover o terminar la arena
void Tablero_logica::cambiarTurno()
{
    if (turnoActual == Bando::LUZ) {
        turnoActual = Bando::OSCURIDAD;
        std::cout << "TURNO DE OSCURIDAD." << std::endl;
    }
    else {
        turnoActual = Bando::LUZ;
        std::cout << "TURNO DE LUZ." << std::endl;
    }
}


//void Tablero_logica::moverCursor(int df, int dc)
//{
//    int nuevaFila = cursor.fila + df;
//    int nuevaColumna = cursor.columna + dc;
//
//    if (posicionValida(nuevaFila, nuevaColumna)) {
//        cursor.fila = nuevaFila;
//        cursor.columna = nuevaColumna;
//
//        std::cout << "Cursor en fila " << cursor.fila
//            << ", columna " << cursor.columna << std::endl;
//    }
//    else {
//        std::cout << "No puedes mover el cursor fuera del tablero." << std::endl;
//    }
//}
//
//bool Tablero_logica::seleccionarConCursor()
//{
//    int f = cursor.fila;
//    int c = cursor.columna;
//
//    if (!hayOrigenSeleccionado) {
//        if (casillas[f][c].ocupante != turnoActual) {
//            std::cout << "No puedes seleccionar esa casilla. No contiene una pieza de tu turno." << std::endl;
//            return false;
//        }
//
//        origenSeleccionado = cursor;
//        hayOrigenSeleccionado = true;
//
//        std::cout << "Origen seleccionado: fila "
//            << origenSeleccionado.fila
//            << ", columna "
//            << origenSeleccionado.columna
//            << std::endl;
//
//        return true;
//    }
//
//    //para ir depurando sin tener la parte gráfica
//    std::cout << "Intentando mover desde fila "
//        << origenSeleccionado.fila
//        << ", columna "
//        << origenSeleccionado.columna
//        << " hasta fila "
//        << f
//        << ", columna "
//        << c
//        << std::endl;
//
//    bool movimientoCorrecto = mover(origenSeleccionado.fila, origenSeleccionado.columna, f, c);
//
//    if (movimientoCorrecto) {
//        std::cout << "Movimiento aceptado." << std::endl;
//    }
//    else {
//        std::cout << "Movimiento invalido." << std::endl;
//    }
//
//    hayOrigenSeleccionado = false;
//    origenSeleccionado = { -1, -1 };
//
//    return movimientoCorrecto;
//}
//
//Posicion Tablero_logica::getCursor() const
//{
//    return cursor;
//}
//
//bool Tablero_logica::getHayOrigenSeleccionado() const
//{
//    return hayOrigenSeleccionado;
//}
//
//Posicion Tablero_logica::getOrigenSeleccionado() const
//{
//    return origenSeleccionado;
//}

void Tablero_logica::dibuja(const Vector2D& centro)const {
    DesacopleGrafico::setCamara(centro, posicionCamaraZ);
    double longitudCasilla = longitud / TAM;
    Vector2D esquinaSuperiorIzda{ centro.x - longitud / 2.0, centro.y + longitud / 2.0 };
    for (unsigned int f = 0; f < TAM; f++) {
        for (unsigned int c = 0; c < TAM; c++) {
            Vector2D centroCasilla{ esquinaSuperiorIzda.x + (c + 0.5) * longitudCasilla, esquinaSuperiorIzda.y - (f + 0.5) * longitudCasilla };
            casillas[f][c].dibuja(centroCasilla, longitudCasilla);
        }
    }
    glClearColor(1.0f, 0.08f, 0.15f, 1.0f);
    glDisable(GL_LIGHTING); // Desactivar luces para el tablero
    glEnable(GL_LIGHTING);
}
