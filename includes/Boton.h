#pragma once
#include <string>
#include "Vector2D.h"
#include "Renderer.h"
using std::string;

class Boton
{
    string texto;
    Color colorArea;
    Color colorPerimetro;
    double escala{ 1.0 };
public:
    Boton(const string& texto)
        : texto(texto)
    {
    }
    void dibuja(const Renderer& renderer, const Vector2D& posicion, const Vector2D& size)const;
    void setParametros(bool estado);
};

