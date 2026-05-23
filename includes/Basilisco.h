#pragma once
#include "Pieza.h"
class Basilisco : public Pieza
{
public:
    Basilisco(Bando b = Bando::OSCURIDAD);
    void dibuja();
};