#pragma once
#include "Pieza.h"
#include "sonidos.h"

class Arquero : public Pieza
{
public:
	Arquero(std::string nombre = "Arquero", TipoPieza tipo = TipoPieza::ARQUERO,  Bando b = Bando::LUZ);

	void dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;

	const Sprite* getSpriteAtaque(const ContenedorSprites& contenedorSprites) override {
		return contenedorSprites.spriteArquero.spriteAtaque.get();
	}

	void reproducirSonidoAtaque() const override { sfx_ataque_disparo.play(); }
};
