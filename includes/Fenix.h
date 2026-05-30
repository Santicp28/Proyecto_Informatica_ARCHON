#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Fenix : public Pieza
{
public:
    Fenix(std::string nombre = "Fenix", Bando b = Bando::LUZ);
    void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const override;
    void reproducirSonidoAtaque() const override { sfx_ataque_explosion.play(); }

};
