#pragma once
#include "Pieza.h"
#include "sonidos.h"

class Manticora : public Pieza
{
public:
    Manticora(std::string nombre = "Manticora", TipoPieza tipo = TipoPieza::MANTICORA, Bando b = Bando::OSCURIDAD);
    void dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
    const Sprite* getSpriteAtaque(const ContenedorSprites& contenedorSprites) override {
        return contenedorSprites.spriteManticora.spriteAtaque.get();
    }
};