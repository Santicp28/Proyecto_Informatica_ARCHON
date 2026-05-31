#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Basilisco : public Pieza
{
public:
    Basilisco(std::string nombre = "Basilisco", Bando b = Bando::ROJO);

    const char* getSpriteAtaque() const override { return basilisco.grafAtaque; }
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
};