#include "Golem.h"
#include "Pieza.h"

Golem::Golem(Bando b) : Pieza(
    Ataque::ALTO,                  // High
    Vida::ALTA,                    // Long
    Velocidad::BAJA,               // Slow
    Cadencia::LENTA,               // Long
    Velocidad_ataque::LENTO,       // Stone chippings (Slow)
    b,
    TipoMovimiento::CAMINA         // Ground
) {
}
void Golem::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(golem.graf, centro, ancho, alto);
}