#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"
class Duende : public Pieza
{
public:
    Duende(Bando b = Bando::OSCURIDAD);
    void dibuja();
};