#pragma once
#include "Pieza.h"
#include "sonidos.h"

class Golem : public Pieza
{
public:
    Golem(std::string nombre = "Golem", TipoPieza tipo = TipoPieza::GOLEM, Bando b = Bando::LUZ);
    void dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
    const Sprite* getSpriteAtaque(const ContenedorSprites& contenedorSprites) override {
        return contenedorSprites.spriteGolem.spriteAtaque.get();
    }
};