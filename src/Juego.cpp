#include "Juego.h"
#include "freeglut.h"
#include "Grafmenu.h"
#include <cstdlib>
#include "Tipos.h"

Juego::Juego() :
    estado(EstadoJuego::MENU_PRINCIPAL),
    tablero(Config::sizeMundo.y*0.75),

    menuPrincipal({ "JUGAR","OPCIONES","SALIR" }, { MenuAccion::JUGAR, MenuAccion::OPCIONES, MenuAccion::SALIR },
        Config::sizeMundo, Config::sizeMundo * 0.5, "ARCHON", { 0.0f, 0.0f, 0.0f }),
	
	menuPausa({ "CONTINUAR","OPCIONES","SALIR" }, { MenuAccion::CONTINUAR, MenuAccion::OPCIONES, MenuAccion::SALIR },
		Config::sizeMundo, Config::sizeMundo * 0.5, "PAUSA", { 0.0f, 0.0f, 0.0f }),

	menuFinPartida({ "JUGAR DE NUEVO","MENU","SALIR" }, { MenuAccion::JUGAR, MenuAccion::IR_MENU_PRINCIPAL, MenuAccion::SALIR },
		Config::sizeMundo, Config::sizeMundo * 0.5, "FIN DE PARTIDA", { 0.0f, 0.0f, 0.0f })
{
}

void Juego::inicializa()
{
    estado = EstadoJuego::MENU_PRINCIPAL;
    menuPrincipal.inicializa();
	menuPausa.inicializa();
	menuFinPartida.inicializa();
    tablero.inicializa();
}

void Juego::dibuja(const Renderer& renderer)
{
    renderer.dibujaColorFondo({ 0.2f, 0.2f, 0.2f });
    switch (estado) {
    case EstadoJuego::MENU_PRINCIPAL:
        menuPrincipal.dibuja(grafmenu, renderer);
        break;

    case EstadoJuego::TABLERO:
        tablero.dibuja(renderer);
        break;

	case EstadoJuego::PAUSA:
		menuPausa.dibuja(renderer);
		break;

    case EstadoJuego::ARENA:   
        arena.dibuja(renderer);
        break;

    case EstadoJuego::OPCIONES:
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        break;

	case EstadoJuego::FIN_PARTIDA:
		menuFinPartida.dibuja(renderer);
		break;
    }
}

void Juego::mueve(float dt)
{
    if (estado == EstadoJuego::ARENA) {
        arena.mueve(dt);
    }
}

void Juego::tecla(unsigned char key)
{
    switch (estado)
    {
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
        TableroAccion accion = tablero.tecla(key);
        switch (accion)
        {
		case TableroAccion::IR_PAUSA:
			estado = EstadoJuego::PAUSA;
			break;
		case TableroAccion::IR_ARENA:
            printf("atacante: %p, defensor: %p\n", tablero.getAtacante(), tablero.getDefensor());
            arena.inicializa(tablero.getAtacante(), tablero.getDefensor());
            estado = EstadoJuego::ARENA;
			break;
        default:
            break;
        }
        break;
    }
    case EstadoJuego::ARENA:
    {
        if (arena.terminado()) {
            if (key == '\t') { // <- solo ENTER, no cualquier tecla
                if (arena.getFinAbsoluto()) {
                    estado = EstadoJuego::FIN_PARTIDA;
                }
                else {
                    bool finJuego = tablero.resultadoCombate(arena.getGanador());
                    arenaResultadoProcesado = true;
                    arena.limpiarJugadores();
                    if (finJuego) {
                        arena.setFinAbsoluto(tablero.getGanador()); // <- AQUÍ
                    }
                    else {
                        estado = EstadoJuego::TABLERO;
                        arenaResultadoProcesado = false;
                    }
                }
            }
        }
        else {
            arena.tecla(key);
        }
        break;

        ////ESTE ESC es para pruebas 
        //if (key == 27) { //también para ir probando como cambia, revisar en siguientes versiones cuando desarrollemos la arena
        //    estado = EstadoJuego::TABLERO;
        //}
        //else {
        //    arena.tecla(key);
        //}

        //break;
    }
    
    case EstadoJuego::OPCIONES:
    {
        if (key == 27) { //desarrollar esto al final
            estado = EstadoJuego::MENU_PRINCIPAL;
        }
        break;
    }
    case EstadoJuego::PAUSA:
    {
        MenuAccion accion = menuPausa.tecla(key);
        switch (accion)
        {
        case MenuAccion::CONTINUAR:
            estado = EstadoJuego::TABLERO;
            break;
        case MenuAccion::OPCIONES:
            estado = EstadoJuego::OPCIONES;
            break;
        case MenuAccion::SALIR:
            exit(0);
            break;
        default:
            break;
        }
        break;
    }
    case EstadoJuego::FIN_PARTIDA:
    {
        MenuAccion accion = menuFinPartida.tecla(key);
        switch (accion)
        {
        case MenuAccion::JUGAR:
            estado = EstadoJuego::TABLERO;
            tablero.inicializa();
            break; {//POR AQUI ME HE QUEDADO
            }
        }
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
            tablero.moverCursor(-1, 0);
            break;

        case GLUT_KEY_DOWN:
            tablero.moverCursor(1, 0);
            break;

        case GLUT_KEY_LEFT:
            tablero.moverCursor(0, -1);
            break;

            case GLUT_KEY_RIGHT:
                tablero.moverCursor(0, 1);
                break;
            }
        }
        else if (estado == EstadoJuego::ARENA) {
            arena.teclaEspecial(key);
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

void Juego::teclaUP(unsigned char key) {
	if (estado == EstadoJuego::ARENA) {
		arena.teclaUP(key);
	}
}
void Juego::teclaEspecialUP(int key) {
    if (estado == EstadoJuego::ARENA) {
        arena.teclaEspecialUP(key);
    }
}