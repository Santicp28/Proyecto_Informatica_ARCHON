#pragma once
#include <string>
#include "Vector2D.h"
#include "Renderer.h"
using std::string;

enum class Seleccion {
    SELECCIONADO,
    NO_SELECCIONADO
};

class Boton
{
    string texto;
    Seleccion estado;
    Color color;
public:
    Boton(const string& texto)
        : texto(texto)
    {
    }
    void dibuja(const Renderer& renderer, const Vector2D& posicion, const Vector2D& size)const;
};

