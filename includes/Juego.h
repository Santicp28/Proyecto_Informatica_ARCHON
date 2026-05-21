#pragma once
#include "Menu.h"
#include "Arena.h"
#include "Tablero_logica.h"
#include"Vector2D.h"
#include "Renderer.h"

enum class EstadoJuego {
    MENU_PRINCIPAL,
    TABLERO,
    ARENA,
    RANKING,
    FIN_PARTIDA
};

class Juego {
private:

    EstadoJuego estado;
    Tablero_logica tablero_logica;
    Menu menu;
    Vector2D centro{ 400.0,300.0 };
//    Arena arena;

public:
    void inicializa();
    void dibuja(const Renderer& renderer);
    void mueve(float dt);

    void tecla(unsigned char key);
    void teclaEspecial(int key);
    void raton(int button, int state, int x, int y);
    void movimientoRaton(int x, int y);

    EstadoJuego getEstado() const;
    void setEstado(EstadoJuego nuevoEstado);
};