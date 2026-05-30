#pragma once
#include "Pieza.h"
class Banshee : public Pieza 
{
public:
    Banshee(std::string nombre = "Banshee", Bando b = Bando::OSCURIDAD);

    void dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
   
};

