#pragma once
#include "Casilla.h"

//esto se usará para simular también las piezas hasta que haya personajes definidos
enum class Bando {
    NINGUNO,
    LUZ,
    OSCURIDAD
};

struct Posicion {
    int fila;
    int columna;
};

class Tablero_logica {
private:
    static const int TAM = 9;
    const Vector2D posicionPrimera;
    Casilla casillas[TAM][TAM];

    //para inicializar los tipos de casillas
    const int layout[9][9] = {
        {0, 1, 0, 2, 3, 2, 0, 1, 0},
        {1, 0, 2, 1, 2, 1, 2, 0, 1},
        {0, 2, 1, 0, 2, 0, 1, 2, 0},
        {2, 1, 0, 1, 2, 1, 0, 1, 2},
        {3, 2, 2, 2, 3, 2, 2, 2, 3},
        {2, 1, 0, 1, 2, 1, 0, 1, 2},
        {0, 2, 1, 0, 2, 0, 1, 2, 0},
        {1, 0, 2, 1, 2, 1, 2, 0, 1},
        {0, 1, 0, 2, 3, 2, 0, 1, 0}
    };

    Bando turnoActual;

    // el cursor es una posicion, la cual usaremos para iluminarla en el teclado con la parte gráfica, así como el origen seleccionado
    Posicion cursor;
    Posicion origenSeleccionado;
    bool hayOrigenSeleccionado;

	//flag cuando dos piezas de bandos opuestos se encuentran en la misma casilla
    bool combatePendiente;

    //estas son para saber cómo terminan las piezas después de la arena
    Posicion origenCombate;
    Posicion destinoCombate;

    float sizeCasillas{ 1.0f };
    int numeroCasillas{ 9 };

public:
    void inicializa();

    //desarrollar como obtener las posiciones seleccionadas y pasarlas a esto !!!!!!!!!!!!!!!!!!!!!
    bool mover(int filaOrigen, int colOrigen, int filaDestino, int colDestino);

    //funcion para obtener el flag si hay combate
    bool hayCombatePendiente() const;
	void limpiarCombatePendiente(); //cuando empieza la arena se limpia el flag de combate pendiente

    //para saber donde está cada pieza después de que se resuelve la arena
    Posicion getOrigenCombate() const;
    Posicion getDestinoCombate() const;

	//para saber de quién es el turno, por ejemplo para mostrar en pantalla
    Bando getTurnoActual() const;

    
    //para otras interacciones futuras como hechizos ...
    Bando getOcupante(int fila, int col) const;
    TipoCasilla getTipoCasilla(int fila, int col) const;


    void moverCursor(int df, int dc);
    bool seleccionarConCursor();

    Posicion getCursor() const;
    bool getHayOrigenSeleccionado() const;
    Posicion getOrigenSeleccionado() const;

    void dibuja()const;//dibuja tablero

private:
    bool posicionValida(int fila, int col) const;

    //para después de mover o terminar la arena
    //hacer una funcion para cuando se termina el combate y aplicar los resultados
    void cambiarTurno();
    void setTileColor(int type);//para dibujar tablero
};