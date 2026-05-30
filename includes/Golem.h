#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Golem : public Pieza
{
public:
    Golem(std::string nombre = "Golem", Bando b = Bando::AZUL);

    const char* getSpriteAtaque() const override { return golem.grafAtaque; }

};