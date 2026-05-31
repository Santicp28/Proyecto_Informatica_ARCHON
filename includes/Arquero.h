#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
#include "sonidos.h"

class Arquero : public Pieza
{
public:
	Arquero(std::string nombre = "Arquero",  Bando b = Bando::AZUL);

	const char* getSpriteAtaque() const override { return arquero.grafAtaque; }
	void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
};
