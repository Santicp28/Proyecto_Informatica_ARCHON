#include "Mago.h"
#include "Pieza.h"

Mago::Mago(Bando b) : Pieza(
    Ataque::ALTO,                  // High
    Vida::MODERADA,                // Average
    Velocidad::NORMAL,             // Normal
    Cadencia::PROMEDIO,            // Average
    Velocidad_ataque::NORMAL,      // Fireball (Middle)
    b,
    TipoMovimiento::TELETRANSPORTE // Teleport
) {
}
void Mago::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(mago.graf, centro, ancho, alto);
}
