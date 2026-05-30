#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Golem : public Pieza
{
public:
    Golem(std::string nombre = "Golem", Bando b = Bando::LUZ);
    void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const override;
    const char* getSpriteAtaque() const override { return golem.grafAtaque; }
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }

};