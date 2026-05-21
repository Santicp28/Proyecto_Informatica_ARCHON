#pragma once
#include <string>
#include "Vector2D.h"
using std::string;

class Boton
{
    Vector2D posicion;
    Vector2D size;
    string texto;
    bool hover;
public:
    void inicializa(const TipoCasilla& nuevoTipo, PosicionMatriz nuevaPosicion);
    void dibuja(const Renderer& renderer, const Vector2D& posicion, double longitud)const;
};

