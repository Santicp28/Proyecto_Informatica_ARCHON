#pragma once
#include "Menu.h"

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
    Menu menu;

public:
    void inicializa();
    void dibuja();
    void mueve(float dt);

    void tecla(unsigned char key);
    void teclaEspecial(int key);
    void raton(int button, int state, int x, int y);
    void movimientoRaton(int x, int y);

    EstadoJuego getEstado() const;
    void setEstado(EstadoJuego nuevoEstado);
};