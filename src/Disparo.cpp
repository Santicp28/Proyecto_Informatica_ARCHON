#include "Disparo.h"
#include "ObjetoMovil.h"
void Disparo::dibuja(const Renderer& renderer) const
{
        renderer.dibujaOvalo(sprite, posicion_,Config::rojo, 50, 50);
}
