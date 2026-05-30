#pragma once
#include "Pieza.h"

class Arquero : public Pieza
{
public:
	Arquero(std::string nombre = "Arquero", Bando b = Bando::LUZ);

	void dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;

};
