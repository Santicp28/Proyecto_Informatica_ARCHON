#pragma once
#include "Pieza.h"
class Manticora : public Pieza
{
public:
    Manticora(Bando b = Bando::OSCURIDAD);
    void dibuja();
};