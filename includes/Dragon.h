#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Dragon : public Pieza
{
public:
    Dragon(std::string nombre = "Dragon", TipoPieza tipo = TipoPieza::DRAGON, Bando b = Bando::OSCURIDAD);
    void reproducirSonidoAtaque() const override { sfx_ataque_fuego.play(); }

};