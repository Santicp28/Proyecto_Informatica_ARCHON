#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Manticora : public Pieza
{
public:
    Manticora(std::string nombre = "Manticora", TipoPieza tipo = TipoPieza::MANTICORA, Bando b = Bando::OSCURIDAD);
    
    const char* getSpriteAtaque() const override { return manticora.grafAtaque; }
};