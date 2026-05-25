#include "freeglut.h"
#include "Pared.h"

void Pared::dibuja(const Renderer& renderer) const
{
    renderer.dibujaLinea(limite1, limite1, color);
}

double Pared::distancia(const Vector2D& p, Vector2D* pdir) const
{
    Vector2D u = (p - limite1), dir,
        v = (limite2 - limite1).unitario();
    if (auto valor = u * v; valor < 0)
        dir = u;
    else if (valor > (limite1 - limite2).modulo())
        dir = (p - limite2);
    else dir = u - v * valor;

    if (pdir != 0) *pdir = dir.unitario();
    return dir.modulo();
}