#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Basilisco : public Pieza
{
public:
    Basilisco(std::string nombre = "Basilisco", Bando b = Bando::OSCURIDAD);

    void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const override;
    const char* getSpriteAtaque() const override { return basilisco.grafAtaque; }
};