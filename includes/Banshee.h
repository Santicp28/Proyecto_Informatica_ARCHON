#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"
class Banshee : public Pieza {
public:
    Banshee(Bando b = Bando::OSCURIDAD);
    void dibuja();
};

