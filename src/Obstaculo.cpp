#include "freeglut.h"
#include "Obstaculo.h"

void Obstaculo::dibuja(const Renderer& renderer) const
{
    renderer.dibujaOvalo(sprite, posicion,Config::verde, size.x, size.y);
}