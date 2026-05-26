#include "Manticora.h"
#include "Pieza.h"

Manticora::Manticora(Bando b) : Pieza(
    Ataque::BAJO,                  // Low
    Vida::MODERADA,                // Average
    Velocidad::NORMAL,             // Normal
    Cadencia::PROMEDIO,            // Average
    Velocidad_ataque::LENTO,      // Spikes (Slow-Normal)
    b,
    TipoMovimiento::CAMINA         // Ground
) {
}
void Manticora::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(manticora.graf, centro, ancho, alto);
}