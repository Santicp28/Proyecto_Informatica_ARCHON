#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Basilisco : public Pieza
{
public:
    Basilisco(std::string nombre = "Basilisco", TipoPieza tipo = TipoPieza::BASILISCO, Bando b = Bando::OSCURIDAD);

    const char* getSpriteAtaque() const override { return basilisco.grafAtaque; }
};