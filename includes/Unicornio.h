#pragma once
#include "Pieza.h"
class Unicornio : public Pieza
{
public:
    Unicornio(std::string nombre = "Unicornio", Bando b = Bando::LUZ);
    void dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
};