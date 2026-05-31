#pragma once
#include "Pieza.h"
#include "sonidos.h"

class Fenix : public Pieza
{
public:
    Fenix(std::string nombre = "Fenix", TipoPieza tipo = TipoPieza::FENIX, Bando b = Bando::LUZ);
    void dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
    void reproducirSonidoAtaque() const override { sfx_ataque_explosion.play(); }

};
