#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Banshee : public Pieza 
{
public:
    Banshee(std::string nombre = "Banshee", Bando b = Bando::ROJO);
    void reproducirSonidoAtaque() const override { sfx_grito_banshee.play(); }
   
};

