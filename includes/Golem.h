#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"
class Golem : public Pieza
{
public:
    Golem(Bando b = Bando::LUZ);
    void dibuja(const Renderer& renderer, const char* rutaPNG, const Vector2D& centro, double ancho, double alto) const;

};