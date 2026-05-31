#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Dragon : public Pieza
{
public:
    Dragon(std::string nombre = "Dragon", TipoPieza tipo = TipoPieza::DRAGON, Bando b = Bando::OSCURIDAD);
    void reproducirSonidoAtaque() const override { sfx_ataque_fuego.play(); }
    Dragon(std::string nombre = "Dragon", Bando b = Bando::OSCURIDAD);
    void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const override;
    const char* getSpriteAtaque() const override { return dragon.grafAtaque; }

};