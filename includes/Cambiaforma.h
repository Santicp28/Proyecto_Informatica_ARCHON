#pragma once
#include "Pieza.h"
#include "sonidos.h"

class Cambiaforma : public Pieza
{
public:
    Cambiaforma(std::string nombre = "Cambiaforma", TipoPieza tipo = TipoPieza::CAMBIAFORMA, Bando b = Bando::OSCURIDAD);
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
    void dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
    const char* getSpriteAtaque() const override { return cambiaforma.grafAtaque; }
};