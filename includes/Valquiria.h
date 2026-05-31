#pragma once
#include "Pieza.h"
#include "sonidos.h"

class Valquiria : public Pieza
{
public:
    Valquiria(std::string nombre = "Valquiria", TipoPieza tipo = TipoPieza::VALQUIRIA, Bando b = Bando::LUZ);
    void dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
    const char* getSpriteAtaque() const override { return valquiria.grafAtaque; }
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
};