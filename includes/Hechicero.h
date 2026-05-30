#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Hechicero : public Pieza
{
public:
    Hechicero(std::string nombre = "Hechicero", Bando b = Bando::ROJO);
    
    const char* getSpriteAtaque() const override { return hechicero.grafAtaque; } 

};