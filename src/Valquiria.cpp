#include "Valquiria.h"
#include "Pieza.h"

Valquiria::Valquiria(Bando b) : Pieza(
    Ataque::MODERADO,              // Moderate
    Vida::MODERADA,                // Average
    Velocidad::NORMAL,             // Normal
    Cadencia::PROMEDIO,            // Average
    Velocidad_ataque::LENTO,       // Spear (Slow)
    b,
    TipoMovimiento::VUELA           // Air
) {
}
void Valquiria::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(valquiria.graf, centro, ancho, alto);
}