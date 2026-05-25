#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"
class Valquiria : public Pieza
{
public:
    Valquiria(Bando b = Bando::LUZ);
    void dibuja();
};