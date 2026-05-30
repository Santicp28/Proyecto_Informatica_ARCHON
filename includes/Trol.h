#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Trol : public Pieza
{
public:
    Trol(std::string nombre = "Trol", Bando b = Bando::ROJO);
    const char* getSpriteAtaque() const override { return trol.grafAtaque; }
};