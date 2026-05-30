#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Manticora : public Pieza
{
public:
    Manticora(std::string nombre = "Manticora", Bando b = Bando::ROJO);
    
    const char* getSpriteAtaque() const override { return manticora.grafAtaque; }
};