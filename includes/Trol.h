#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"
class Trol : public Pieza
{
public:
    Trol(Bando b = Bando::OSCURIDAD);
    void dibuja(const Renderer& renderer, const char* rutaPNG, const Vector2D& centro, double ancho, double alto) const;

};