#include "freeglut.h"
#include "Obstaculo.h"

void Obstaculo::dibuja(const Renderer& renderer) const
{
    renderer.dibujaSprite(sprite, posicion, size.x, size.y);
}