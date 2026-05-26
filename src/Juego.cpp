#include "Juego.h"
#include "freeglut.h"
#include <cstdlib>
#include "Tipos.h"

void Juego::inicializa()
{
    estado = EstadoJuego::MENU_PRINCIPAL;
    menuPrincipal.inicializa();
    Tablero.inicializa();
}

void Juego::dibuja(const Renderer& renderer)
{
    renderer.dibujaColorFondo({ 0.2f, 0.2f, 0.2f });
    switch (estado) {
    case EstadoJuego::MENU_PRINCIPAL:
        menuPrincipal.dibuja(renderer);
        break;

    case EstadoJuego::TABLERO:
        Tablero.dibuja(renderer);
        break;

    case EstadoJuego::ARENA:   
        arena.dibuja(renderer);
        break;

    case EstadoJuego::OPCIONES:
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
    switch (estado){
        case EstadoJuego::MENU_PRINCIPAL:
        {

            MenuAccion accion = menuPrincipal.tecla(key);

            switch (accion)
            {
            case MenuAccion::JUGAR:
                estado = EstadoJuego::TABLERO;
                break;

            case MenuAccion::OPCIONES:
                estado = EstadoJuego::ARENA;
                break;

            case MenuAccion::SALIR:
                exit(0);
                break;

            default:
                break;
            }
            break;
        }

        case EstadoJuego::TABLERO:
        {
            if (key == 13) { // ENTER
                Tablero.seleccionarConCursor();


                //tablero avisa de que se he elegido combate, haciendo que juego ponga el estado ARENA y limpiando el flag del combate pendiente para no volver a entrar 
                if (Tablero.hayCombatePendiente()) {
                    estado = EstadoJuego::ARENA;
                    Tablero.limpiarCombatePendiente();
                }


                if (key == 27) { // ESC
                    estado = EstadoJuego::MENU_PRINCIPAL;
                }
                if (key == 'h') {
                    estado = EstadoJuego::MENU_HECHIZOS;
                }
                
            }
			break;
        }
        case EstadoJuego::MENU_HECHIZOS:
        {

            MenuAccion accion = menu.tecla(key);

            switch (accion)
            {
            case MenuAccion::JUGAR:
                estado = EstadoJuego::TABLERO;
                break;

            case MenuAccion::OPCIONES:
                estado = EstadoJuego::ARENA;
                break;

            case MenuAccion::SALIR:
                exit(0);
                break;

            default:
                break;
            }
            break;
        }
        case EstadoJuego::ARENA:
        {
            if (key == 27) { //también para ir probando como cambia, revisar en siguientes versiones cuando desarrollemos la arena
                estado = EstadoJuego::TABLERO;
            }
            break;
        }
        case EstadoJuego::OPCIONES:
        {
            if (key == 27) { //desarrollar esto al final
                estado = EstadoJuego::MENU_PRINCIPAL;
            }
            break;
        }
        case EstadoJuego::FIN_PARTIDA:
        {
            if (key == 27) { //desarrollar esto al final
                estado = EstadoJuego::MENU_PRINCIPAL;
            }
            break;
        }
    }
}

    void Juego::teclaEspecial(int key)
    {
        if (estado == EstadoJuego::MENU_PRINCIPAL) {
            menuPrincipal.teclaEspecial(key);
        }
        else if (estado == EstadoJuego::TABLERO) { //con esto conseguimos mover el cursor mediante las flechas en el teclado
            switch (key) {
            case GLUT_KEY_UP:
                Tablero.moverCursor(-1, 0);
                break;

            case GLUT_KEY_DOWN:
                Tablero.moverCursor(1, 0);
                break;

            case GLUT_KEY_LEFT:
                Tablero.moverCursor(0, -1);
                break;

            case GLUT_KEY_RIGHT:
                Tablero.moverCursor(0, 1);
                break;
            }
        }
    }


    //void Juego::raton(int button, int state, int x, int y) //ejemplo para probar el menú, a cambiar en futuras versiones
    //{
    //    if (estado == EstadoJuego::MENU_PRINCIPAL) {
    //        menuPrincipal.raton(button, state, x, y, 600);
    //
    //        if (menuPrincipal.getQuiereJugar()) {
    //            estado = EstadoJuego::TABLERO;
    //            menuPrincipal.resetAcciones();
    //        }
    //        else if (menuPrincipal.getQuiereRanking()) {
    //            estado = EstadoJuego::RANKING;
    //            menuPrincipal.resetAcciones();
    //        }
    //        else if (menuPrincipal.getQuiereSalir()) {
    //            exit(0);
    //        }
    //    }
    //}

    //void Juego::movimientoRaton(int x, int y)
    //{
    //    if (estado == EstadoJuego::MENU_PRINCIPAL) {
    //        menuPrincipal.movimientoRaton(x, y, 600);
    //    }
    //}

    EstadoJuego Juego::getEstado() const
    {
        return estado;
    } //geters para interacciones con otras partes

    void Juego::setEstado(EstadoJuego nuevoEstado)
    {
        estado = nuevoEstado;
    }
