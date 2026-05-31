#pragma once
#include "Pieza.h"
#include "sonidos.h"

class Banshee : public Pieza 
{
public:
    Banshee(std::string nombre = "Banshee", TipoPieza tipo = TipoPieza::BANSHEE, Bando b = Bando::OSCURIDAD);
    void reproducirSonidoAtaque() const override { sfx_grito_banshee.play(); }
    void dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;

};

