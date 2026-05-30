#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Manticora : public Pieza
{
public:
    Manticora(std::string nombre = "Manticora", Bando b = Bando::OSCURIDAD);
    

    void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const override;
    const char* getSpriteAtaque() const override { return manticora.grafAtaque; }
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
};