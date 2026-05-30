#pragma once
#include "Vector2D.h"
#include "Renderer.h"

class Panel
{
	protected:
		Vector2D size;
		Vector2D posicion;
		Color colorFondo;
		Color colorTexto;
		Color colorTitulo;
		Color colorBorde;
		std::string titulo;


	public:
		Panel(Vector2D size, Vector2D posicion, Color colorFondo, Color colorTexto, Color colorTitulo, Color colorBorde, const std::string& titulo) 
			: size(size), posicion(posicion), colorFondo(colorFondo), colorTexto(colorTexto), colorTitulo(colorTitulo), colorBorde(colorBorde), titulo(titulo) {}

		virtual void dibuja(const Renderer& renderer) const = 0;

		virtual ~Panel(){}
};
