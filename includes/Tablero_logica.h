#pragma once
#include "Casilla.h"
#include "Pieza.h"
#include <vector>
#include "Tipos.h"
#include "ListaPiezas.h"
#include "Interaccion.h"


class Tablero_logica {
private:
    static const int TAM = 9;
    const Vector2D posicionPrimera;
    Casilla casillas[TAM][TAM];

    ListaPiezas listaPiezas;
    Interaccion interacciones;
    Bando turnoActual;

    // el cursor es una posicion, la cual usaremos para iluminarla en el teclado con la parte gráfica, así como el origen seleccionado
    PosicionMatriz cursor;
    PosicionMatriz origenSeleccionado;
    bool hayOrigenSeleccionado;

	//flag cuando dos piezas de bandos opuestos se encuentran en la misma casilla
    bool combatePendiente;

    //estas son para saber cómo terminan las piezas después de la arena
    PosicionMatriz origenCombate;
    PosicionMatriz destinoCombate;

    float sizeCasillas{ 1.0f };
    int numeroCasillas{ 9 };


public:
    void inicializa();




    //desarrollar como obtener las posiciones seleccionadas y pasarlas a esto !!!!!!!!!!!!!!!!!!!!!
    bool mover(Casilla origen, Casilla destino);

    //funcion para obtener el flag si hay combate
    bool hayCombatePendiente() const;
	void limpiarCombatePendiente(); //cuando empieza la arena se limpia el flag de combate pendiente

    //para saber donde está cada pieza después de que se resuelve la arena
    PosicionMatriz getOrigenCombate() const;
    PosicionMatriz getDestinoCombate() const;

	//para saber de quién es el turno, por ejemplo para mostrar en pantalla
    Bando getTurnoActual() const;

    
    //para otras interacciones futuras como hechizos ...
    Bando getOcupante(int fila, int col) const;
    TipoCasilla getTipoCasilla(int fila, int col) const;


    void moverCursor(int df, int dc);
    bool seleccionarConCursor();

    PosicionMatriz getCursor() const;
    bool getHayOrigenSeleccionado() const;
    PosicionMatriz getOrigenSeleccionado() const;

    void dibuja()const;//dibuja tablero

private:
    bool posicionValida(int fila, int col) const;

    //para después de mover o terminar la arena
    //hacer una funcion para cuando se termina el combate y aplicar los resultados
    void cambiarTurno();
};