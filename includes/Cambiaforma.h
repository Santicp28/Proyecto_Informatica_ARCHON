#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Cambiaforma : public Pieza
{
public:
    Cambiaforma(std::string nombre = "Cambiaforma", TipoPieza tipo = TipoPieza::CAMBIAFORMA, Bando b = Bando::OSCURIDAD);
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }

    Cambiaforma(std::string nombre = "Cambiaforma", Bando b = Bando::OSCURIDAD);
    
    void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const override;
    const char* getSpriteAtaque() const override { return cambiaforma.grafAtaque; }
};