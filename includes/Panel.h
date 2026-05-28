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
		int tam_texto_escalado;
		int tam_titulo_escalado;

	public:
		Panel(Vector2D size, Vector2D posicion, Color colorFondo, Color colorTexto, Color colorTitulo, Color colorBorde, const std::string& titulo, int tam_texto_escalado, int tam_titulo_escalado) 
			: size(size), posicion(posicion), colorFondo(colorFondo), colorTexto(colorTexto), colorTitulo(colorTitulo), colorBorde(colorBorde), titulo(titulo), tam_texto_escalado(tam_texto_escalado), tam_titulo_escalado(tam_titulo_escalado) {}

		virtual void dibuja(const Renderer& renderer) const = 0;

		virtual ~Panel(){}
};
