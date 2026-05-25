#include "Bordes.h"
#include "freeglut.h"

Bordes::Bordes(const Vector2D& size, const Vector2D& centro) 
    : techo(centro - size * 0.5, { centro.x + size.x * 0.5, centro.y - size.y * 0.5 },color),
    suelo({ centro.x - size.x * 0.5, centro.y + size.y * 0.5 }, centro + size * 0.5, color),
    izq(centro - size * 0.5, { centro.x - size.x * 0.5, centro.y + size.y * 0.5 }, color),
    dcha({ centro.x + size.x * 0.5, centro.y - size.y * 0.5 }, centro + size * 0.5, color)
{
}

void Bordes::dibuja(const Renderer& renderer) const
{
    suelo.dibuja(renderer);
    techo.dibuja(renderer);
    izq.dibuja(renderer);
    dcha.dibuja(renderer);
}