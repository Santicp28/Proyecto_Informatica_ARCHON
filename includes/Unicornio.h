#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Unicornio : public Pieza
{
public:
    Unicornio(std::string nombre = "Unicornio", Bando b = Bando::AZUL);
    const char* getSpriteAtaque() const override { return unicornio.grafAtaque; }
};