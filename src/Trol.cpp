#include "Trol.h"
#include "Pieza.h"

Trol::Trol(Bando b) : Pieza(
    Ataque::ALTO,                  // High
    Vida::ALTA,                    // Long
    Velocidad::BAJA,               // Slow
    Cadencia::LENTA,               // Long
    Velocidad_ataque::LENTO,       // Rocks (Slow)
    b,
    TipoMovimiento::CAMINA         // Ground
) {
}
void Trol::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(trol.graf, centro, ancho, alto);
}
