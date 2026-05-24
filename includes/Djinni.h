#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"
class Djinni : public Pieza
{
public:
    Djinni(Bando b = Bando::LUZ);
    void dibuja();
};
