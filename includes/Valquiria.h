#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Valquiria : public Pieza
{
public:
    Valquiria(std::string nombre = "Valquiria", Bando b = Bando::LUZ);
    void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const override;
    const char* getSpriteAtaque() const override { return valquiria.grafAtaque; }
};