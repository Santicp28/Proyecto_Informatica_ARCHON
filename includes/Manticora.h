#pragma once
#include "Pieza.h"
class Manticora : public Pieza
{
public:
    Manticora(std::string nombre = "Manticora", Bando b = Bando::OSCURIDAD);
    

    void dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
};