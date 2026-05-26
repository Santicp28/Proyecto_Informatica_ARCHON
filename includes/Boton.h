#pragma once
#include <string>
#include "Vector2D.h"
#include "Renderer.h"
using std::string;

class Boton
{
    string texto;
    Color colorArea{ 0.2f, 0.25f, 0.4f };
    Color colorPerimetro{ 1.0f,1.0f,1.0f };
    double escala{ 1.0 };
    bool seleccionado{ false };
public:
    Boton(const string& texto)
        : texto(texto)
    {
    }
    void inicializa() { seleccionado = false; }
    void dibuja(const Renderer& renderer, const Vector2D& posicion, const Vector2D& size)const;
    void cambiarEstado();
};

