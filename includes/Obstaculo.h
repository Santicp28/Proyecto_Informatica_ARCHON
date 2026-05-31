#pragma once
#include "Vector2D.h"
#include "Renderer.h"
#include "ContenedorSprites.h"
class Obstaculo
{
public:
    Vector2D posicion;
    Vector2D size;
    const unique_ptr<ETSIDI::Sprite> sprite;

    Obstaculo() = default;
    Obstaculo(const Vector2D& pos, const Vector2D& sz, const unique_ptr<ETSIDI::Sprite>& spr)
        : posicion(pos), size(sz), sprite(spr.get()) {
    }

    void dibuja(const Renderer& renderer) const;
};
