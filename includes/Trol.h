#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Trol : public Pieza
{
public:
    Trol(std::string nombre = "Trol", Bando b = Bando::OSCURIDAD);
    void dibuja(const Renderer& renderer,const Vector2D& centro, double ancho, double alto) const override;
    const char* getSpriteAtaque() const override { return trol.grafAtaque; }
};