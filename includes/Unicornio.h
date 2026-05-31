#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Unicornio : public Pieza
{
public:
    Unicornio(std::string nombre = "Unicornio", TipoPieza tipo = TipoPieza::UNICORNIO, Bando b = Bando::LUZ);
    const char* getSpriteAtaque() const override { return unicornio.grafAtaque; }
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
};