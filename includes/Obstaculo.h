#pragma once
#include "Vector2D.h"
#include "Renderer.h"
class Obstaculo
{
public:
    Vector2D posicion;
    Vector2D size;
    ETSIDI::Sprite sprite;

    Obstaculo() = default;
    Obstaculo(const Vector2D& pos, const Vector2D& sz, const ETSIDI::Sprite& spr)
        : posicion(pos), size(sz), sprite(spr) {
    }

    void dibuja(const Renderer& renderer) const;
};

