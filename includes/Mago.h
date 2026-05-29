#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Mago : public Pieza
{
public:
    Mago(std::string nombre = "Mago", Bando b = Bando::LUZ);
    
    void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const override;

    const char* getSpriteAtaque() const override { return mago.grafAtaque; }

};