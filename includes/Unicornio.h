#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Unicornio : public Pieza
{
public:
    Unicornio(std::string nombre = "Unicornio", Bando b = Bando::LUZ);
    void dibuja(const Renderer& renderer,const Vector2D& centro, double ancho, double alto) const override;
    const char* getSpriteAtaque() const override { return unicornio.grafAtaque; }
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
};