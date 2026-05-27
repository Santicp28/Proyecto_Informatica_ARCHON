#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Duende : public Pieza
{
public:
    Duende(Bando b = Bando::OSCURIDAD);

    void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const override;

};