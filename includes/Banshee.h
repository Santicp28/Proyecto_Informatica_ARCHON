#pragma once
#include "Pieza.h"
class Banshee : public Pieza {
public:
    Banshee(Bando b = Bando::OSCURIDAD);
    void dibuja();
};

