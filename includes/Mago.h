#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Mago : public Pieza
{
public:
    Mago(std::string nombre = "Mago", Bando b = Bando::AZUL);
    

    const char* getSpriteAtaque() const override { return mago.grafAtaque; }

};