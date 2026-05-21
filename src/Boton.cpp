#include "Boton.h"
void Boton::dibuja(const Renderer& renderer, const Vector2D& posicion, const Vector2D& size) const
{
    renderer.dibujaCuadrado(posicion, color, size);
    renderer.dibujaContornoCuadrado(posicion, { 0.5f, 0.5f, 0.5f }, size);
}