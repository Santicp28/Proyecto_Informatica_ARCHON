#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Manticora : public Pieza
{
public:
    Manticora(std::string nombre = "Manticora", Bando b = Bando::ROJO);
    
    const char* getSpriteAtaque() const override { return manticora.grafAtaque; }
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
};