#pragma once
#include "Pieza.h"
class Cambiaforma : public Pieza
{
public:
    Cambiaforma(Bando b = Bando::OSCURIDAD);
    void dibuja();
};