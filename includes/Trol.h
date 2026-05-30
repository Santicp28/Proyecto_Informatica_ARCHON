#pragma once
#include "Pieza.h"
class Trol : public Pieza
{
public:
    Trol(std::string nombre = "Trol", Bando b = Bando::OSCURIDAD);
    void dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
};