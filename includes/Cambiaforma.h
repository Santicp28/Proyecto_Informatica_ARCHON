#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Cambiaforma : public Pieza
{
public:
    Cambiaforma(std::string nombre = "Cambiaforma", TipoPieza tipo = TipoPieza::CAMBIAFORMA, Bando b = Bando::OSCURIDAD);
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
    const char* getSpriteAtaque() const override { return cambiaforma.grafAtaque; }
    void copiarStatsSuperiores(const Pieza& rival);
};