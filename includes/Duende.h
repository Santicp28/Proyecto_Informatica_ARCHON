#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"
class Duende : public Pieza
{
public:
    Duende(Bando b = Bando::OSCURIDAD);

    void dibuja(const Renderer& renderer, const char* rutaPNG, const Vector2D& centro, double ancho, double alto) const;

};