#include "freeglut.h"
#include "disparo.h"
#include "ObjetoMovil.h"
void Disparo::dibuja(const Renderer& renderer) const
{
    if (sprite)
        renderer.dibujaSprite(sprite, posicion_, sizeradio_, sizeradio_);
}
