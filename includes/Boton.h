#pragma once
#include <string>
#include "Vector2D.h"
#include "Renderer.h"
#include "ContenedorSprites.h"
using std::string;

class Boton
{
    string texto;
    Color colorArea{ 0.2f, 0.25f, 0.4f };
    Color colorPerimetro{ 1.0f,1.0f,1.0f };
	Color colorTexto{ 0.0f,0.0f,0.0f };
    double escala{ 1.0 };
    bool activo{ true };
    bool seleccionado{ false };
public:
    Boton(const string& texto)
        : texto(texto)
    {
    }
    void inicializa() { seleccionado = false; activo = true; }
    void dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& posicion, const Vector2D& size)const;
    void cambiarEstado();
	void desactivarBoton() { activo = false; }
	void activarBoton() { activo = true; }
	bool estaDesactivo() const { return !activo; }
};

