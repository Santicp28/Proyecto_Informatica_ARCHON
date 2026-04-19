#pragma once

#include <string>
#include <vector>

using namespace std;

struct Boton {
    float x, y, w, h;
    string texto;
    bool hover;
};

class Menu {
private:
    vector<Boton> botones;
    bool quiere_jugar;
    bool quiere_salir;
    bool quiere_ranking;

    bool estaDentro(const Boton& b, int x, int y, int altoVentana) const;
    void dibujarTexto(float x, float y, const std::string& texto) const;

public:
    void inicializa(int anchoVentana, int altoVentana);
    void dibuja();
    void mueve(float dt);

    void tecla(unsigned char key);
    void teclaEspecial(int key);
    void raton(int button, int state, int x, int y, int altoVentana);
    void movimientoRaton(int x, int y, int altoVentana);

    bool getQuiereJugar() const;
    bool getQuiereSalir() const;
    bool getQuiereRanking() const;

    void resetAcciones();
};