#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"
class Valquiria : public Pieza
{
public:
    Valquiria(Bando b = Bando::LUZ);
    void dibuja(const Vector2D& centro, double ancho, double alto) const;


};