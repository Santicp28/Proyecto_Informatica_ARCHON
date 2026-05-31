#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Fenix : public Pieza
{
public:
    Fenix(std::string nombre = "Fenix", TipoPieza tipo = TipoPieza::FENIX, Bando b = Bando::LUZ);
    void reproducirSonidoAtaque() const override { sfx_ataque_explosion.play(); }

};
