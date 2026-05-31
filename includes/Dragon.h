#pragma once
#include "Pieza.h"
#include "sonidos.h"

class Dragon : public Pieza
{
public:
    Dragon(std::string nombre = "Dragon", TipoPieza tipo = TipoPieza::DRAGON, Bando b = Bando::OSCURIDAD);
    void dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
    void reproducirSonidoAtaque() const override { sfx_ataque_fuego.play(); }
    const char* getSpriteAtaque() const override { return dragon.grafAtaque; }

};