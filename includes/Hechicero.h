#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Hechicero : public Pieza
{
public:
    Hechicero(std::string nombre = "Hechicero", TipoPieza tipo = TipoPieza::HECHICERO, Bando b = Bando::OSCURIDAD);
    
    const char* getSpriteAtaque() const override { return hechicero.grafAtaque; } 
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
};