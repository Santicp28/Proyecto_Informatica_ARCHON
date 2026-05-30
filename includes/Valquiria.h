#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Valquiria : public Pieza
{
public:
    Valquiria(std::string nombre = "Valquiria", Bando b = Bando::AZUL);
    const char* getSpriteAtaque() const override { return valquiria.grafAtaque; }
};