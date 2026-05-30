#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Mago : public Pieza
{
public:
    Mago(std::string nombre = "Mago", TipoPieza tipo = TipoPieza::MAGO, Bando b = Bando::LUZ);
    

    const char* getSpriteAtaque() const override { return mago.grafAtaque; }

};