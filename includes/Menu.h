#pragma once
#include"Renderer.h"
#include "Boton.h"
#include<string>
#include <vector>
using std::vector, std::string;

class Menu {
    vector<Boton> botones;
    unsigned int seleccionado{ 0 };

    bool estaDentro(const Boton& b, int x, int y, int altoVentana) const;
    void dibujarTexto(float x, float y, const std::string& texto) const;

public:
    Menu(const std::vector<std::string>& textos)
    {
        for (const auto& texto : textos)
            botones.emplace_back(texto);//cuando pasas argumentos del constructor:emplace_back (llama constructor sin hacer copia temporal). Cuando ya tienes el objeto creado:push_back
    }

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