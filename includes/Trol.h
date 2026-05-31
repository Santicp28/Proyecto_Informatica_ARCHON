#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Trol : public Pieza
{
public:
    Trol(std::string nombre = "Trol", TipoPieza tipo = TipoPieza::TROL, Bando b = Bando::OSCURIDAD);
    const char* getSpriteAtaque() const override { return trol.grafAtaque; }
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
};