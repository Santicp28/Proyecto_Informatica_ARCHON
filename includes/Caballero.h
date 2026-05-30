#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Caballero : public Pieza
{
public:
    Caballero(std::string nombre = "Caballero", TipoPieza tipo = TipoPieza::CABALLERO, Bando b = Bando::LUZ);
 
    void reproducirSonidoAtaque() const override { sfx_ataque_melee.play(); }
    ~Caballero() { delete golpe; golpe = nullptr; }
};