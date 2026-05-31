#pragma once
#include "Pieza.h"
#include "sonidos.h"

class Basilisco : public Pieza
{
public:
    Basilisco(std::string nombre = "Basilisco", TipoPieza tipo = TipoPieza::BASILISCO, Bando b = Bando::OSCURIDAD);

    void dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
    const Sprite* getSpriteAtaque(const ContenedorSprites& contenedorSprites) override {
        return contenedorSprites.spriteBasilisco.spriteAtaque.get();
    }
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
};