#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"
class Hechicero : public Pieza
{
public:
    Hechicero(Bando b = Bando::OSCURIDAD);
    void dibuja();
};