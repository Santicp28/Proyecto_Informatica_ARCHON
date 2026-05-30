#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Caballero : public Pieza
{
public:
    Caballero(std::string nombre = "Caballero", Bando b = Bando::LUZ);
 
    void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const override;
    void reproducirSonidoAtaque() const override { sfx_ataque_melee.play(); }
    ~Caballero() { delete golpe; golpe = nullptr; }
};