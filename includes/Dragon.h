#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"
class Dragon : public Pieza
{
public:
    Dragon(Bando b = Bando::OSCURIDAD);
    void dibuja();
};