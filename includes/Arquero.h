#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"

class Arquero : public Pieza
{
public:
	Arquero(std::string nombre = "Arquero", Bando b = Bando::LUZ);

	void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const override;

	const char* getSpriteAtaque() const override { return arquero.grafAtaque; }
};
