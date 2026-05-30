#pragma once
#include "Pieza.h"
class Duende : public Pieza
{
public:
    Duende(std::string nombre = "Duende", Bando b = Bando::OSCURIDAD);

    void dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;

};