#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"
class Unicornio : public Pieza
{
public:
    Unicornio(Bando b = Bando::LUZ);
    void dibuja();
};