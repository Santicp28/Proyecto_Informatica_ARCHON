#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Banshee : public Pieza 
{
public:
    Banshee(std::string nombre = "Banshee", Bando b = Bando::OSCURIDAD);

    void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const override;
    void reproducirSonidoAtaque() const override { sfx_grito_banshee.play(); }
   
};

