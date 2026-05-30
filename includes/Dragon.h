#pragma once
#include "Pieza.h"
class Dragon : public Pieza
{
public:
    Dragon(std::string nombre = "Dragon", Bando b = Bando::OSCURIDAD);
    void dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;

};