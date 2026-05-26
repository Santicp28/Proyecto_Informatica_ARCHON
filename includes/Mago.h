#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"
class Mago : public Pieza
{
public:
    Mago(Bando b = Bando::LUZ);
    void dibuja(const Vector2D& centro, double ancho, double alto) const;

};