#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Djinni : public Pieza
{
public:
    Djinni(std::string nombre = "Djinni", Bando b = Bando::LUZ);
    
    void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const override;
    const char* getSpriteAtaque() const override { return djinni.grafAtaque; }
};
