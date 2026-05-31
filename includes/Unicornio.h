#pragma once
#include "Pieza.h"
#include "sonidos.h"

class Unicornio : public Pieza
{
public:
    Unicornio(std::string nombre = "Unicornio", TipoPieza tipo = TipoPieza::UNICORNIO, Bando b = Bando::LUZ);
    void dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
    const Sprite* getSpriteAtaque(const ContenedorSprites& contenedorSprites) override {
        return contenedorSprites.spriteUnicornio.spriteAtaque.get();
    }
};