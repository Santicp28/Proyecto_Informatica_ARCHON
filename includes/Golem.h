#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"
class Golem : public Pieza
{
public:
    Golem(Bando b = Bando::LUZ);
    void dibuja();
};