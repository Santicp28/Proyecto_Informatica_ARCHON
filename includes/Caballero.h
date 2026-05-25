#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"

class Caballero : public Pieza
{
public:
    Caballero(Bando b = Bando::LUZ);
    void dibuja(const Vector2D& centro, double ancho, double alto) const;

};