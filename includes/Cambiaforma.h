#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Cambiaforma : public Pieza
{
public:
    Cambiaforma(std::string nombre = "Cambiaforma", Bando b = Bando::ROJO);
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
    const char* getSpriteAtaque() const override { return cambiaforma.grafAtaque; }
    void copiarStatsSuperiores(const Pieza& rival);
};