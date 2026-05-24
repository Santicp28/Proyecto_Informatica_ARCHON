#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"
class Fenix : public Pieza
{
public:
    Fenix(Bando b = Bando::LUZ);
    void dibuja();
};
