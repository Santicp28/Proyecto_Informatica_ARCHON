#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"
class Manticora : public Pieza
{
public:
    Manticora(Bando b = Bando::OSCURIDAD);
    void dibuja();
};