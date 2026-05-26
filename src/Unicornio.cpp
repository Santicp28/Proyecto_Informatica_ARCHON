#include "Unicornio.h"
#include "Pieza.h"

Unicornio::Unicornio(Bando b) : Pieza(
    Ataque::MODERADO,              // Moderate
    Vida::MODERADA,                // Average
    Velocidad::NORMAL,             // Normal
    Cadencia::LENTA,            // Average
    Velocidad_ataque::RAPIDO,      // Energy bolts (Fast)
    b,
    TipoMovimiento::CAMINA         // Ground
) {
}
void Unicornio::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(unicornio.graf, centro, ancho, alto);
}