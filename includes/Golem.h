#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Golem : public Pieza
{
public:
    Golem(std::string nombre = "Golem", Bando b = Bando::LUZ);
    void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const override;

};