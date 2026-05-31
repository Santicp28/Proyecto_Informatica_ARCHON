#pragma once
#include "Pieza.h"
#include "sonidos.h"

class Mago : public Pieza
{
public:
    Mago(std::string nombre = "Mago", TipoPieza tipo = TipoPieza::MAGO, Bando b = Bando::LUZ);
    
    void dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
    void reproducirSonidoAtaque() const override { sfx_ataque_fuego.play(); }
    const Sprite* getSpriteAtaque(const ContenedorSprites& contenedorSprites) override {
        return contenedorSprites.spriteMago.spriteAtaque.get();
    }
};