#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Hechicero : public Pieza
{
public:
    Hechicero(std::string nombre = "Hechicero", Bando b = Bando::OSCURIDAD);
    
    void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const override;
    const char* getSpriteAtaque() const override { return hechicero.grafAtaque; } 

};