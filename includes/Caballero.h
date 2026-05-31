#pragma once
#include "Pieza.h"
#include "sonidos.h"

class Caballero : public Pieza
{
public:
    Caballero(std::string nombre = "Caballero", TipoPieza tipo = TipoPieza::CABALLERO, Bando b = Bando::LUZ);
 
    void reproducirSonidoAtaque() const override { sfx_ataque_melee.play(); }
    void dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;

    ~Caballero() { delete golpe; golpe = nullptr; }
};