#include "Juego.h"
#include "freeglut.h"
#include <cstdlib>
#include "Tipos.h"

Juego::Juego() :
    estado(EstadoJuego::MENU_PRINCIPAL),

    tablero(Config::sizeMundo.y),

    menuPrincipal({ "JUGAR","OPCIONES","SALIR" }, { MenuAccion::JUGAR, MenuAccion::OPCIONES, MenuAccion::SALIR },
        Config::sizeMundo, Config::sizeMundo * 0.5, "ARCHON", { 0.0f, 0.0f, 0.0f }),

    menuHechizosLuz( { "TP","CURAR","TIEMPO","SWITCH","SPAWN","1UP","CARCEL","SALIR"},
        { MenuAccion::TP, MenuAccion::CURAR, MenuAccion::CAMBIAR_TIEMPO, MenuAccion::INTERCAMBIAR, MenuAccion::ENCARCELAR, MenuAccion::TIJERAS },
        { (Config::sizeMundo.x - Config::sizeMundo.y) * 0.5, Config::sizeMundo.y },
        { (Config::sizeMundo.x - Config::sizeMundo.y) * 0.5*0.5, Config::sizeMundo.y*0.5 }, "LUZ", { 1.0f, 0.0f, 0.0f }),

    menuHechizosOscuridad( { "TP","CURAR","TIEMPO","SWITCH","SPAWN","1UP","CARCEL","SALIR" },
        { MenuAccion::TP, MenuAccion::CURAR, MenuAccion::CAMBIAR_TIEMPO, MenuAccion::INTERCAMBIAR, MenuAccion::ENCARCELAR, MenuAccion::TIJERAS },
        { (Config::sizeMundo.x - Config::sizeMundo.y) * 0.5, Config::sizeMundo.y },
        { (Config::sizeMundo.x - Config::sizeMundo.y) * 0.5*0.5, Config::sizeMundo.y*0.5 }, "OSC", { 0.0f, 1.0f, 0.0f })
{
}

void Juego::inicializa()
{
    estado = EstadoJuego::MENU_PRINCIPAL;
    menuPrincipal.inicializa();
	menuHechizosLuz.inicializa();
	menuHechizosOscuridad.inicializa();
    tablero.inicializa();
}

void Juego::dibuja(const Renderer& renderer)
{
    renderer.dibujaColorFondo({ 0.2f, 0.2f, 0.2f });
    switch (estado) {
    case EstadoJuego::MENU_PRINCIPAL:
        menuPrincipal.dibuja(renderer);
        break;

    case EstadoJuego::TABLERO:
        tablero.dibuja(renderer);
        break;

	case EstadoJuego::MENU_HECHIZOS_LUZ:
        tablero.dibuja(renderer);
		menuHechizosLuz.dibuja(renderer);
		break;

	case EstadoJuego::MENU_HECHIZOS_OSCURIDAD:
        tablero.dibuja(renderer);
		menuHechizosOscuridad.dibuja(renderer);
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
                tablero.seleccionarConCursor();

                if (tablero.comprobarFinJuego()) {
                    estado = EstadoJuego::FIN_PARTIDA;
                    break;
                }

            //tablero avisa de que se he elegido combate, haciendo que juego ponga el estado ARENA y limpiando el flag del combate pendiente para no volver a entrar 
            if (tablero.hayCombatePendiente()) {
                estado = EstadoJuego::ARENA;
                tablero.limpiarCombatePendiente();
            }
        }
            if (key == 27) { // ESC
                estado = EstadoJuego::MENU_PRINCIPAL;
            }
            if (key == 'h') {
				Bando turno = tablero.getTurnoActual();
                if (turno == Bando::LUZ)
                    estado = EstadoJuego::MENU_HECHIZOS_LUZ;
                else
                    estado = EstadoJuego::MENU_HECHIZOS_OSCURIDAD;
            }
		break;
        }
        case EstadoJuego::MENU_HECHIZOS_LUZ:
        {
            MenuAccion accion = menuHechizosLuz.tecla(key);

            switch (accion)
            {
            case MenuAccion::TP:
                break;

            case MenuAccion::CURAR:
                break;

            case MenuAccion::CAMBIAR_TIEMPO:
                break;

            case MenuAccion::INTERCAMBIAR:
                break;

            case MenuAccion::ENCARCELAR:
                break;

            case MenuAccion::TIJERAS:
                break;

            case MenuAccion::SALIR:
				estado = EstadoJuego::TABLERO;
                break;

            default:
                break;
            }
            break;
        }
		case EstadoJuego::MENU_HECHIZOS_OSCURIDAD:
		{
			MenuAccion accion = menuHechizosOscuridad.tecla(key);
            switch (accion)
            {
            case MenuAccion::TP:
                break;

            case MenuAccion::CURAR:
                break;

            case MenuAccion::CAMBIAR_TIEMPO:
                break;

            case MenuAccion::INTERCAMBIAR:
                break;

            case MenuAccion::ENCARCELAR:
                break;

            case MenuAccion::TIJERAS:
                break;

            case MenuAccion::SALIR:
                estado = EstadoJuego::TABLERO;
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
}


EstadoJuego Juego::getEstado() const
{
    return estado;
} //geters para interacciones con otras partes

void Juego::setEstado(EstadoJuego nuevoEstado)
{
    estado = nuevoEstado;
}
