#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Duende : public Pieza
{
public:
    Duende(std::string nombre = "Duende", Bando b = Bando::OSCURIDAD);

    void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const override;
    void reproducirSonidoAtaque() const override { sfx_ataque_melee.play(); }
    ~Duende() { delete golpe; golpe = nullptr; }
};