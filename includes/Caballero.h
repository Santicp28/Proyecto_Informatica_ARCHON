#pragma once
#include "Pieza.h"
class Caballero : public Pieza
{
public:
    Caballero(Bando b = Bando::LUZ);
    void dibuja();
};