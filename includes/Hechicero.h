#pragma once
#include "Pieza.h"
#include "sonidos.h"

class Hechicero : public Pieza
{
public:
    Hechicero(std::string nombre = "Hechicero", TipoPieza tipo = TipoPieza::HECHICERO, Bando b = Bando::OSCURIDAD);
    
    const char* getSpriteAtaque() const override { return hechicero.grafAtaque; } 
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
    void dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
};