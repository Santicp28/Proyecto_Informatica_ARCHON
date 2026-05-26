#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"
class Unicornio : public Pieza
{
public:
    Unicornio(Bando b = Bando::LUZ);
    void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const;

};