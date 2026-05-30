#pragma once
#include "Pieza.h"
class Fenix : public Pieza
{
public:
    Fenix(std::string nombre = "Fenix", Bando b = Bando::LUZ);
    void dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;

};
