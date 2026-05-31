#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Banshee : public Pieza 
{
public:
    Banshee(std::string nombre = "Banshee", TipoPieza tipo = TipoPieza::BANSHEE, Bando b = Bando::OSCURIDAD);
    void reproducirSonidoAtaque() const override { sfx_grito_banshee.play(); }
   
};

