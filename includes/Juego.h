#pragma once
#include "Menu.h"
#include "Arena.h"
#include "Tablero_logica.h"
#include"Vector2D.h"
#include "Renderer.h"
#include "Tipos.h"

enum class EstadoJuego {
    MENU_PRINCIPAL,
    TABLERO,
    ARENA,
    OPCIONES,
    PAUSA,
    FIN_PARTIDA
};

class Juego {
private:

    EstadoJuego estado;
    Tablero_logica tablero_logica;
    Menu menu{ { "JUGAR","OPCIONES","SALIR" } };
//    Arena arena;

public:
    void inicializa();
    void dibuja(const Renderer& renderer);
    void mueve(float dt);

    void tecla(unsigned char key);
    void teclaEspecial(int key);
};