#pragma once
#include "Menu.h"
#include "Arena.h"
#include "Tablero.h"
#include"Vector2D.h"
#include "Renderer.h"
#include "Tipos.h"

enum class EstadoJuego {
    MENU_PRINCIPAL,
    TABLERO,
    MENU_HECHIZOS,
    ARENA,
    OPCIONES,
    PAUSA,
    FIN_PARTIDA
};

class Juego {
private:
    EstadoJuego estado;
    Tablero Tablero;
    Menu menuPrincipal{ { "JUGAR","OPCIONES","SALIR" },Config::sizeMundo,Config::sizeMundo*0.5, "Archon"};
    Menu menuHechizos{ { "TP","CURAR","CAMBIAR TIEMPO","INTERCAMBIAR","INVOCAR","REVIVIR","ENCARCELAR","SALIR"},
        {(Config::sizeMundo.x - longitud) * 0.5}, "HECHIZOS" }; //CAMBIAR
    Arena arena;

public:
    void inicializa();
    void dibuja(const Renderer& renderer);
    void mueve(float dt);

    void tecla(unsigned char key);
    void teclaEspecial(int key);
    void teclaUP(unsigned char key);
    void teclaEspecialUP(int key);
    EstadoJuego getEstado() const;
    void setEstado(EstadoJuego nuevoEstado);
};