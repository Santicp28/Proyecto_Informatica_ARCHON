#include "Juego.h"
#include "freeglut.h"
#include <cstdlib>

void Juego::inicializa()
{
    estado = EstadoJuego::MENU_PRINCIPAL;
    menu.inicializa(800, 600);
    tablero_logica.inicializa();
}

void Juego::dibuja()
{
    //fondos de colores para ir viendo si funciona, ir implementado las funciones de Adrián
    switch (estado) {
    case EstadoJuego::MENU_PRINCIPAL:
        menu.dibuja();
        break;

    case EstadoJuego::TABLERO:
        gluLookAt(0.0, 0.0, 15.0,//// posición de la cámara
            0.0, 0.0, 0.0, // punto al que mira
            0.0, 1.0, 0.0);// vector "arriba" (define por asi decirlo la gravedad)
        tablero_logica.dibuja();
        break;

    case EstadoJuego::ARENA:
        glClearColor(0.25f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //arena.dibuja();
        break;

    case EstadoJuego::RANKING:
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        break;

    case EstadoJuego::FIN_PARTIDA:
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        break;
    }
}

void Juego::mueve(float dt)
{

}

void Juego::tecla(unsigned char key)
{
    switch (estado) {

    case EstadoJuego::MENU_PRINCIPAL:
        menu.tecla(key);

        if (menu.getQuiereJugar()) {
            estado = EstadoJuego::TABLERO;
            menu.resetAcciones();
        }
        else if (menu.getQuiereRanking()) {
            estado = EstadoJuego::RANKING;
            menu.resetAcciones();
        }
        else if (menu.getQuiereSalir()) {
            exit(0);
        }
        break;

    case EstadoJuego::TABLERO:
        if (key == 13) { // ENTER
            tablero_logica.seleccionarConCursor();


            //tablero avisa de que se he elegido combate, haciendo que juego ponga el estado ARENA y limpiando el flag del combate pendiente para no volver a entrar 
            if (tablero_logica.hayCombatePendiente()) {
                estado = EstadoJuego::ARENA;
                tablero_logica.limpiarCombatePendiente();
            }
        }

        if (key == 27) { // ESC
            estado = EstadoJuego::MENU_PRINCIPAL;
        }
        break;

    case EstadoJuego::ARENA:
        if (key == 27) { //también para ir probando como cambia, revisar en siguientes versiones cuando desarrollemos la arena
            estado = EstadoJuego::TABLERO;
        }
        break;

    case EstadoJuego::RANKING:
        if (key == 27) { //desarrollar esto al final
            estado = EstadoJuego::MENU_PRINCIPAL;
        }
        break;

    case EstadoJuego::FIN_PARTIDA:
        if (key == 27) { //desarrollar esto al final
            estado = EstadoJuego::MENU_PRINCIPAL;
        }
        break;
    }
}

void Juego::teclaEspecial(int key)
{
    if (estado == EstadoJuego::MENU_PRINCIPAL) {
        menu.teclaEspecial(key);
    }
    else if (estado == EstadoJuego::TABLERO) { //con esto conseguimos mover el cursor mediante las flechas en el teclado
        switch (key) {
        case GLUT_KEY_UP:
            tablero_logica.moverCursor(-1, 0);
            break;

        case GLUT_KEY_DOWN:
            tablero_logica.moverCursor(1, 0);
            break;

        case GLUT_KEY_LEFT:
            tablero_logica.moverCursor(0, -1);
            break;

        case GLUT_KEY_RIGHT:
            tablero_logica.moverCursor(0, 1);
            break;
        }
    }
}


void Juego::raton(int button, int state, int x, int y) //ejemplo para probar el menú, a cambiar en futuras versiones
{
    if (estado == EstadoJuego::MENU_PRINCIPAL) {
        menu.raton(button, state, x, y, 600);

        if (menu.getQuiereJugar()) {
            estado = EstadoJuego::TABLERO;
            menu.resetAcciones();
        }
        else if (menu.getQuiereRanking()) {
            estado = EstadoJuego::RANKING;
            menu.resetAcciones();
        }
        else if (menu.getQuiereSalir()) {
            exit(0);
        }
    }
}

void Juego::movimientoRaton(int x, int y)
{
    if (estado == EstadoJuego::MENU_PRINCIPAL) {
        menu.movimientoRaton(x, y, 600);
    }
}

EstadoJuego Juego::getEstado() const
{
    return estado;
} //geters para interacciones con otras partes

void Juego::setEstado(EstadoJuego nuevoEstado)
{
    estado = nuevoEstado;
}