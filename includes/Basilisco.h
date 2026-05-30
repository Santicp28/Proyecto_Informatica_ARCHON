#pragma once
#include "Pieza.h"
class Basilisco : public Pieza
{
public:
    Basilisco(std::string nombre = "Basilisco", Bando b = Bando::OSCURIDAD);

    void dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
};