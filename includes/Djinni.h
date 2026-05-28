#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Djinni : public Pieza
{
public:
    Djinni(Bando b = Bando::LUZ);
    
    void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const override;
};
