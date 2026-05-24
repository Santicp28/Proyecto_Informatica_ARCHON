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


    //INICIALIZA PIEZAS --------- PONER SU POSICION INICIAL
    //PIEZAS LUZ
    //listaPiezas.agregar(new );
    //listaPiezas.agregar(new );
    //listaPiezas.agregar(new );

    ////PIEZAS OSCURIDAD
    //listaPiezas.agregar(new );
    //listaPiezas.agregar(new );
    //listaPiezas.agregar(new );
    //INICIALIZA PIEZAS

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


bool Tablero_logica::mover(PosicionMatriz origen, PosicionMatriz destino) //CADA PIEZA SE MUEVE DISTINTO
{

    Bando atacante = interaccion.getBandoOcupante(origen, listaPiezas);
    Bando defensor = interaccion.getBandoOcupante(destino, listaPiezas);

    //ILUMINAR O DESTACAR CASILLA SI HAY ERROR O MOSTRAR UN SONIDO O ALGO, TAMBIEN MOSTRAR MENSAJE PARA SABER EL ERROR
    
	//Hay una pieza aliada en destino
    if (defensor == atacante) {
        std::cout << "Movimiento invalido: la casilla destino tiene una pieza aliada." << std::endl;
        return false;
    }

    //Si hay enemigo, no movemos todavía
    //Dejamos marcado que tiene que abrirse la arena.
    if (defensor != Bando::NINGUNO && defensor != atacante) {
        combatePendiente = true; //FLAG PARA CAMBIAR A ARENA
        origenCombate = origen;
        destinoCombate = destino;

        std::cout << "Combate pendiente entre origen (" << origenCombate.fila << ", " << origenCombate.columna
            << ") y destino (" << destinoCombate.fila << ", " << destinoCombate.columna << ")." << std::endl;

        return true;
    }

    //Movimiento normal
	listaPiezas.moverDeCasilla(origen, destino);

    std::cout << "Pieza movida correctamente de (" << origen.fila << ", " << origen.columna << ") a (" << destino.fila << ", " << destino.columna << ")." << std::endl;

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
        cursor = { 4 , 8}; //cursor en el lado de oscuridad
        std::cout << "TURNO DE OSCURIDAD." << std::endl;
    }
    else {
        turnoActual = Bando::LUZ;
		cursor = { 4 , 0 }; //cursor en el lado de luz
        std::cout << "TURNO DE LUZ." << std::endl;
    }
}

//comprueba si se puede mover y luego asigna la nueva posicion al cursor, se llama desde juego cuando se pulsa una flecha
void Tablero_logica::moverCursor(int df, int dc)
{
	PosicionMatriz nuevaPosicion{ cursor.fila + df, cursor.columna + dc };

    if (interaccion.posicionValida(nuevaPosicion)) {
		cursor = nuevaPosicion;
        std::cout << "cursor en fila " << cursor.fila << ", columna " << cursor.columna << std::endl;
    }
    else {
        std::cout << "no puedes mover el cursor fuera del tablero" << std::endl;
    }
}



bool Tablero_logica::seleccionarConCursor()
{

    if (!hayOrigenSeleccionado) {
        if (interaccion.getBandoOcupante(cursor, listaPiezas) != turnoActual) {
            std::cout << "no puedes seleccionar esa casilla. no contiene una pieza de tu turno." << std::endl;
            return false;
        }

        origenSeleccionado = cursor;
        hayOrigenSeleccionado = true;

        std::cout << "origen seleccionado: fila " << origenSeleccionado.fila << ", columna " << origenSeleccionado.columna << std::endl;

        return true;
    }

    //para ir depurando sin tener la parte gráfica
    std::cout << "intentando mover desde fila "<< origenSeleccionado.fila << ", columna " << origenSeleccionado.columna
        << " hasta fila "<< cursor.fila << ", columna " << cursor.columna << std::endl;

    


    bool movimientoCorrecto = mover(origenSeleccionado, cursor);

    if (movimientoCorrecto) {
        std::cout << "movimiento aceptado." << std::endl;
    }
    else {
        std::cout << "movimiento invalido." << std::endl;
    }

    hayOrigenSeleccionado = false;

	origenSeleccionado = { -1, -1 };//reiniciamos el origen seleccionado para evitar errores

    return movimientoCorrecto;
}

PosicionMatriz Tablero_logica::getCursor() const
{
    return cursor;
}

bool Tablero_logica::getHayOrigenSeleccionado() const
{
    return hayOrigenSeleccionado;
}

PosicionMatriz Tablero_logica::getOrigenSeleccionado() const
{
    return origenSeleccionado;
}

void resaltarMovimientoPosible()
{

}