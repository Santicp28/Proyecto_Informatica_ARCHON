#pragma once
#include "Pieza.h"
class Fenix : public Pieza
{
public:
    Fenix(Bando b = Bando::LUZ);
    void dibuja();
};
