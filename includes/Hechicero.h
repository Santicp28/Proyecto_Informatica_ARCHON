#pragma once
#include "Pieza.h"
class Hechicero : public Pieza
{
public:
    Hechicero(Bando b = Bando::OSCURIDAD);
    void dibuja();
};