#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Djinni : public Pieza
{
public:
    Djinni(std::string nombre = "Djinni", TipoPieza tipo = TipoPieza::DJINNI, Bando b = Bando::LUZ);
    
    const char* getSpriteAtaque() const override { return djinni.grafAtaque; }
    void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
};
