#pragma once
#include "Pieza.h"
#include "sonidos.h"

class Hechicero : public Pieza
{
public:
    Hechicero(std::string nombre = "Hechicero", TipoPieza tipo = TipoPieza::HECHICERO, Bando b = Bando::OSCURIDAD);
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
    void dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
    const Sprite* getSpriteAtaque(const ContenedorSprites& contenedorSprites) override {
        return contenedorSprites.spriteHechicero.spriteAtaque.get();
    }
};