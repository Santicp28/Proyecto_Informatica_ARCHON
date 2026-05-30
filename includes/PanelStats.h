#pragma once
#include "Panel.h"
#include "Vector2D.h"
#include "Renderer.h"
#include "Pieza.h"

class PanelStats : public Panel
{
	const Pieza* pieza;

public:
	PanelStats(Vector2D size, Vector2D posicion, Color colorFondo, Color colorTexto, Color colorTitulo, Color colorBorde, const std::string& titulo, int escalaTexto, int escalaTitulo)
		: Panel(size, posicion, colorFondo, colorTexto, colorTitulo, colorBorde, titulo, escalaTexto, escalaTitulo) { pieza = nullptr; }

	void dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites) const;
	void setPieza(const Pieza* nuevaPieza) { pieza = nuevaPieza; }

	~PanelStats() override {}

private:
	void dibujaLineaStat(const Renderer& renderer, const char* nombre, double valor, Vector2D posicionTexto) const;
};
	