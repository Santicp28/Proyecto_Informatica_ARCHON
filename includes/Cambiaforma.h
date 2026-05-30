#pragma once
#include "Pieza.h"
class Cambiaforma : public Pieza
{
public:
    Cambiaforma(std::string nombre = "Cambiaforma", Bando b = Bando::OSCURIDAD);
    
    void dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
};