#pragma once
#include "Pieza.h"
class Dragon : public Pieza
{
public:
    Dragon(Bando b = Bando::OSCURIDAD);
    void dibuja();
};