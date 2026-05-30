#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Duende : public Pieza
{
public:
    Duende(std::string nombre = "Duende", TipoPieza tipo = TipoPieza::DUENDE, Bando b = Bando::OSCURIDAD);

    void reproducirSonidoAtaque() const override { sfx_ataque_melee.play(); }
    ~Duende() { delete golpe; golpe = nullptr; }
};