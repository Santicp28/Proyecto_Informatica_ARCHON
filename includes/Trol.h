#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"
class Trol : public Pieza
{
public:
    Trol(Bando b = Bando::OSCURIDAD);
    void dibuja();
};