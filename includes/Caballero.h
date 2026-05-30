#pragma once
#include "Pieza.h"

class Caballero : public Pieza
{
public:
    Caballero(std::string nombre = "Caballero", Bando b = Bando::LUZ);
    
    void dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
};