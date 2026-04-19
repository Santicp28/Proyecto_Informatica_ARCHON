#include "Juego.h"
#include "freeglut.h"
#include <cstdlib>

void Juego::inicializa()
{
    estado = EstadoJuego::MENU_PRINCIPAL;
    menu.inicializa(800, 600);
}

void Juego::dibuja()
{
    switch (estado) {
    case EstadoJuego::MENU_PRINCIPAL:
        menu.dibuja();
        break;

    case EstadoJuego::TABLERO:
        glClearColor(0.1f, 0.25f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        break;

    case EstadoJuego::ARENA:
        glClearColor(0.25f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
    if (estado == EstadoJuego::MENU_PRINCIPAL) {
        menu.mueve(dt);
    }
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

    default:
        if (key == 27)
            estado = EstadoJuego::MENU_PRINCIPAL;
        break;
    }
}

void Juego::teclaEspecial(int key)
{
    if (estado == EstadoJuego::MENU_PRINCIPAL) {
        menu.teclaEspecial(key);
    }
}

void Juego::raton(int button, int state, int x, int y)
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
}

void Juego::setEstado(EstadoJuego nuevoEstado)
{
    estado = nuevoEstado;
}