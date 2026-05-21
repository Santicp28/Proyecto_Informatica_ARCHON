#pragma once
#include"Renderer.h"
#include "Boton.h"
#include <vector>
using std::vector;

class Menu {
    static constexpr int tam = 9;
    Boton botones[tam];
    bool quiere_jugar;
    bool quiere_salir;
    bool quiere_ranking;

    bool estaDentro(const Boton& b, int x, int y, int altoVentana) const;
    void dibujarTexto(float x, float y, const std::string& texto) const;

public:
    void inicializa();
    void dibuja(const Renderer& renderer);

    void tecla(unsigned char key);
    void teclaEspecial(int key);
    void raton(int button, int state, int x, int y, int altoVentana);
    void movimientoRaton(int x, int y, int altoVentana);

    bool getQuiereJugar() const;
    bool getQuiereSalir() const;
    bool getQuiereRanking() const;

    void resetAcciones();
};