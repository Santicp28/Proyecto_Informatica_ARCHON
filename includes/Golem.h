#pragma once
#include "Pieza.h"
class Golem : public Pieza
{
public:
    Golem(std::string nombre = "Golem", Bando b = Bando::LUZ);
    void dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
};