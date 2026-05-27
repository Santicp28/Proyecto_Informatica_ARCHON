#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Cambiaforma : public Pieza
{
public:
    Cambiaforma(Bando b = Bando::OSCURIDAD);
    
    void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const override;
};