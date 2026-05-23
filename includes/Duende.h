#pragma once
#include "Pieza.h"
class Duende : public Pieza
{
public:
    Duende(Bando b = Bando::OSCURIDAD);
    void dibuja();
};