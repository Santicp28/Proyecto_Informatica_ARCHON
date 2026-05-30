#pragma once
#include "Pieza.h"
class Valquiria : public Pieza
{
public:
    Valquiria(std::string nombre = "Valquiria", Bando b = Bando::LUZ);
    void dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
};