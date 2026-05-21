#pragma once
#include "Casilla.h"
#include "Pieza.h"
#include <vector>
#include "Tipos.h"
#include "ListaPiezas.h"
#include "Interaccion.h"
#include "Renderer.h"
#define TAM 9

class Tablero_logica {
private:

    const Vector2D centro{ 0.0, 0.0 };
    double posicionCamaraZ{ 15.0 };
    const double longitud{ 500.0 };

    Casilla casillas[TAM][TAM];

    ListaPiezas listaPiezas;
    Interaccion interaccion;
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
public:
    void inicializa();


public:
    void dibuja(const Renderer& renderer)const;
    void inicializa();

    bool mover(PosicionMatriz origen, PosicionMatriz destino);

    //funcion para obtener el flag si hay combate
    bool hayCombatePendiente() const;
	void limpiarCombatePendiente(); //cuando empieza la arena se limpia el flag de combate pendiente

    //para saber donde está cada pieza después de que se resuelve la arena
    PosicionMatriz getOrigenCombate() const;
    PosicionMatriz getDestinoCombate() const;

	//para saber de quién es el turno, por ejemplo para mostrar en pantalla
    Bando getTurnoActual() const;


    //DESARROLLAR ESTAS !!!!!!!!!!!!!!!!!!!!!!!!!!!!
    void moverCursor(int df, int dc);
    bool seleccionarConCursor();

    PosicionMatriz getCursor() const;
    bool getHayOrigenSeleccionado() const;
    PosicionMatriz getOrigenSeleccionado() const;

    void dibuja(const Vector2D& centro)const;

private:

    //para después de mover o terminar la arena
    //hacer una funcion para cuando se termina el combate y aplicar los resultados
      void cambiarTurno();
};