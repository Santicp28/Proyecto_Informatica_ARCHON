#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Golem : public Pieza
{
public:
    Golem(std::string nombre = "Golem", TipoPieza tipo = TipoPieza::GOLEM, Bando b = Bando::LUZ);

    const char* getSpriteAtaque() const override { return golem.grafAtaque; }
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }

};