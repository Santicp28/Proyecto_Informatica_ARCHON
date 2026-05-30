#pragma once
#include "Pieza.h"
class Hechicero : public Pieza
{
public:
    Hechicero(std::string nombre = "Hechicero", Bando b = Bando::OSCURIDAD);
    
    void dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
};