#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"
class Hechicero : public Pieza
{
public:
    Hechicero(Bando b = Bando::OSCURIDAD);
    
    void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const override;

};