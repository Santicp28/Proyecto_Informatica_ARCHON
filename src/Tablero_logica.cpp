#include "Tablero_logica.h"
#include <iostream>
#include"freeglut.h"
#include 

void Tablero_logica::inicializa()
{
    turnoActual = Bando::LUZ;
    combatePendiente = false;

    cursor = { 0, 0 };
    origenSeleccionado = { -1, -1 };
    hayOrigenSeleccionado = false;


    for (int f = 0; f < TAM; f++) {
        for (int c = 0; c < TAM; c++) {
            switch (layout[f][c]) {
            case 0:
                casillas[f][c].setTipo(TipoCasilla::OSCURA);
                break;
            case 1:
                casillas[f][c].setTipo(TipoCasilla::CLARA);
                break;
            case 2:
                casillas[f][c].setTipo(TipoCasilla::OSCILANTE);
                break;
            case 3:
                casillas[f][c].setTipo(TipoCasilla::PODER);
                break;
            default:
                casillas[f][c].setTipo(TipoCasilla::INVALIDA);
                break;
            }

            
        }
    }

    //Colocación provisional
    for (int f = 0; f < TAM; f++) {
        casillas[f][0].ocupante = Bando::LUZ;
        casillas[f][1].ocupante = Bando::LUZ;

        casillas[f][7].ocupante = Bando::OSCURIDAD;
        casillas[f][8].ocupante = Bando::OSCURIDAD;
    }
}

bool Tablero_logica::mover(int filaOrigen, int colOrigen, int filaDestino, int colDestino) //PONER SWITCH CASE EN FUNCION DEL OCUPANTE, CADA PIEZA SE MUEVE DISTINTO
{
    if (!posicionValida(filaOrigen, colOrigen)) {
        std::cout << "Movimiento invalido: origen fuera del tablero." << std::endl;
        return false;
    }

    if (!posicionValida(filaDestino, colDestino)) {
        std::cout << "Movimiento invalido: destino fuera del tablero." << std::endl;
        return false;
    }

    Bando atacante = casillas[filaOrigen][colOrigen].ocupante;
    Bando defensor = casillas[filaDestino][colDestino].ocupante;

    //No hay pieza en origen.

    if (atacante == Bando::NINGUNO) {
        std::cout << "Movimiento invalido: no hay pieza en el origen." << std::endl;
        return false;
    }


    //No es el turno de ese bando.
    if (atacante != turnoActual) {
        std::cout << "Movimiento invalido: no es el turno de esa pieza." << std::endl;
        return false;
    }

    //No puedes moverte sobre una pieza aliada.
    if (defensor == atacante) {
        std::cout << "Movimiento invalido: la casilla destino tiene una pieza aliada." << std::endl;
        return false;
    }

    //Si hay enemigo, no movemos todavía
    //Dejamos marcado que tiene que abrirse la arena.
    if (defensor != Bando::NINGUNO && defensor != atacante) {
        combatePendiente = true;
        origenCombate = { filaOrigen, colOrigen };
        destinoCombate = { filaDestino, colDestino };

        std::cout << "Combate pendiente entre origen ("
            << filaOrigen << ", " << colOrigen
            << ") y destino ("
            << filaDestino << ", " << colDestino
            << ")." << std::endl;

        return true;
    }

    //Movimiento normal
    casillas[filaDestino][colDestino].ocupante = atacante;
    casillas[filaOrigen][colOrigen].ocupante = Bando::NINGUNO;

    std::cout << "Pieza movida correctamente de ("
        << filaOrigen << ", " << colOrigen
        << ") a ("
        << filaDestino << ", " << colDestino
        << ")." << std::endl;

    cambiarTurno();

    std::cout << "Turno cambiado." << std::endl;

    return true;
}

bool Tablero_logica::hayCombatePendiente() const
{
    return combatePendiente;
}

void Tablero_logica::limpiarCombatePendiente()
{
    combatePendiente = false;
}

Posicion Tablero_logica::getOrigenCombate() const
{
    return origenCombate;
}

Posicion Tablero_logica::getDestinoCombate() const
{
    return destinoCombate;
}

Bando Tablero_logica::getTurnoActual() const
{
    return turnoActual;
}

Bando Tablero_logica::getOcupante(int fila, int col) const
{
    if (!posicionValida(fila, col))
        return Bando::NINGUNO;

    return casillas[fila][col].ocupante;
}

TipoCasilla Tablero_logica::getTipoCasilla(int fila, int col) const
{
    if (!posicionValida(fila, col))
        return TipoCasilla::INVALIDA;

    return casillas[fila][col].tipo;
}

bool Tablero_logica::posicionValida(int fila, int col) const
{
    return fila >= 0 && fila < TAM && col >= 0 && col < TAM;
}

void Tablero_logica::cambiarTurno()
{
    if (turnoActual == Bando::LUZ) {
        turnoActual = Bando::OSCURIDAD;
        std::cout << "Ahora juega OSCURIDAD." << std::endl;
    }
    else {
        turnoActual = Bando::LUZ;
        std::cout << "Ahora juega LUZ." << std::endl;
    }
}

void Tablero_logica::moverCursor(int df, int dc)
{
    int nuevaFila = cursor.fila + df;
    int nuevaColumna = cursor.columna + dc;

    if (posicionValida(nuevaFila, nuevaColumna)) {
        cursor.fila = nuevaFila;
        cursor.columna = nuevaColumna;

        std::cout << "Cursor en fila " << cursor.fila
            << ", columna " << cursor.columna << std::endl;
    }
    else {
        std::cout << "No puedes mover el cursor fuera del tablero." << std::endl;
    }
}

bool Tablero_logica::seleccionarConCursor()
{
    int f = cursor.fila;
    int c = cursor.columna;

    if (!hayOrigenSeleccionado) {
        if (casillas[f][c].ocupante != turnoActual) {
            std::cout << "No puedes seleccionar esa casilla. No contiene una pieza de tu turno." << std::endl;
            return false;
        }

        origenSeleccionado = cursor;
        hayOrigenSeleccionado = true;

        std::cout << "Origen seleccionado: fila "
            << origenSeleccionado.fila
            << ", columna "
            << origenSeleccionado.columna
            << std::endl;

        return true;
    }

    //para ir depurando sin tener la parte gráfica
    std::cout << "Intentando mover desde fila "
        << origenSeleccionado.fila
        << ", columna "
        << origenSeleccionado.columna
        << " hasta fila "
        << f
        << ", columna "
        << c
        << std::endl;

    bool movimientoCorrecto = mover(origenSeleccionado.fila, origenSeleccionado.columna, f, c);

    if (movimientoCorrecto) {
        std::cout << "Movimiento aceptado." << std::endl;
    }
    else {
        std::cout << "Movimiento invalido." << std::endl;
    }

    hayOrigenSeleccionado = false;
    origenSeleccionado = { -1, -1 };

    return movimientoCorrecto;
}

Posicion Tablero_logica::getCursor() const
{
    return cursor;
}

bool Tablero_logica::getHayOrigenSeleccionado() const
{
    return hayOrigenSeleccionado;
}

Posicion Tablero_logica::getOrigenSeleccionado() const
{
    return origenSeleccionado;
}

void Tablero_logica::dibuja()const {
    
    for (auto& fila : tablero)
    {
        for (auto& casilla : fila)
        {
            casilla.dibuja(posicionPrimera);
        }
    }
    
    
    int layout[9][9] = {
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
    glClearColor(1.0f, 0.08f, 0.15f, 1.0f);
    glDisable(GL_LIGHTING); // Desactivar luces para el tablero
    float startPos = -(numeroCasillas * sizeCasillas) / 2.0f;

    for (int row = 0; row < numeroCasillas; ++row) {
        for (int col = 0; col < sizeCasillas; ++col) {
            float x = startPos + col * sizeCasillas;
            float y = startPos + row * sizeCasillas;

            // 1. Dibujar el fondo de la casilla
            setTileColor(layout[row][col]);
            glBegin(GL_QUADS);
            glVertex3f(x, y, 0.0f);
            glVertex3f(x + sizeCasillas, y, 0.0f);
            glVertex3f(x + sizeCasillas, y + sizeCasillas, 0.0f);
            glVertex3f(x, y + sizeCasillas, 0.0f);
            glEnd();

            // 2. Dibujar el borde con un pequeño offset en Z para evitar parpadeo
            glColor3f(1.0f, 0.0f, 0.0f); // Gris oscuro para bordes elegantes
            glLineWidth(2.0f);
            glBegin(GL_LINE_LOOP);
            glVertex3f(x, y, 0.01f);
            glVertex3f(x + sizeCasillas, y, 0.01f);
            glVertex3f(x + sizeCasillas, y + sizeCasillas, 0.01f);
            glVertex3f(x, y + sizeCasillas, 0.01f);
            glEnd();
        }
    }
    glEnable(GL_LIGHTING);
}

void Tablero_logica::setTileColor(int type) {
    switch (type) {
    case 0: glColor3f(0.05f, 0.05f, 0.05f); break; // Negro
    case 1: glColor3f(0.95f, 0.95f, 0.95f); break; // Blanco
    case 2: glColor3f(0.50f, 0.50f, 0.50f); break; // Gris (Shifting)
    case 3: glColor3f(0.00f, 0.80f, 0.80f); break; // Cian (Power Point)
    default: glColor3f(0.3f, 0.3f, 0.3f);
    }
}