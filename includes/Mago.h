#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Mago : public Pieza
{
public:
    Mago(std::string nombre = "Mago", TipoPieza tipo = TipoPieza::MAGO, Bando b = Bando::LUZ);
    

    const char* getSpriteAtaque() const override { return mago.grafAtaque; }
    void reproducirSonidoAtaque() const override { sfx_ataque_fuego.play(); }

};