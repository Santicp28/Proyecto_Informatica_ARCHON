#pragma once
#include "Pieza.h"
class Mago : public Pieza
{
public:
    Mago(std::string nombre = "Mago", Bando b = Bando::LUZ);
    
    void dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;

};