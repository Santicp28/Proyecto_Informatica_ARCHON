#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Valquiria : public Pieza
{
public:
    Valquiria(std::string nombre = "Valquiria", TipoPieza tipo = TipoPieza::VALQUIRIA, Bando b = Bando::LUZ);
    const char* getSpriteAtaque() const override { return valquiria.grafAtaque; }
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
};