#pragma once
#include "Pieza.h"
#include "sonidos.h"

class Djinni : public Pieza
{
public:
    Djinni(std::string nombre = "Djinni", TipoPieza tipo = TipoPieza::DJINNI, Bando b = Bando::LUZ);
    
    const char* getSpriteAtaque() const override { return djinni.grafAtaque; }
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
    void dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;
};
