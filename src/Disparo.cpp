#include "freeglut.h"
#include "disparo.h"
#include "ObjetoMovil.h"
void Disparo::dibuja(const Renderer& renderer) const
{
    renderer.dibujaOvalo(posicion_, { 1.0f, 0.0f, 0.0f }, sizeradio_ * 0.5, sizeradio_);
}

