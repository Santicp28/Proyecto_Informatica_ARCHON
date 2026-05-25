#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"

class Caballero : public Pieza
{
public:
    Caballero(Bando b = Bando::LUZ);
    void dibuja();
};