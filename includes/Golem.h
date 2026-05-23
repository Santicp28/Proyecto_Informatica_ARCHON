#pragma once
#include "Pieza.h"
class Golem : public Pieza
{
public:
    Golem(Bando b = Bando::LUZ);
    void dibuja();
};