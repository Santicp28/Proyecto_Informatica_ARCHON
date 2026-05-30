#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Djinni : public Pieza
{
public:
    Djinni(std::string nombre = "Djinni", Bando b = Bando::AZUL);
    
    const char* getSpriteAtaque() const override { return djinni.grafAtaque; }
};
