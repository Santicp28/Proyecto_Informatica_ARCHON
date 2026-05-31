#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Fenix : public Pieza
{
public:
    Fenix(std::string nombre = "Fenix", Bando b = Bando::AZUL);
    void reproducirSonidoAtaque() const override { sfx_ataque_explosion.play(); }

};
