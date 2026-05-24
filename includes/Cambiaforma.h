#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"
class Cambiaforma : public Pieza
{
public:
    Cambiaforma(Bando b = Bando::OSCURIDAD);
    void dibuja();
};