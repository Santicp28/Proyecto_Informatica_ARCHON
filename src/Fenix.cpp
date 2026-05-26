#include "Fenix.h"
#include "Pieza.h"

Fenix::Fenix(Bando b) : Pieza(
    Ataque::ALTO,                  // High
    Vida::ALTA,                    // Long
    Velocidad::NORMAL,             // Normal
    Cadencia::LENTA,            // Average
    Velocidad_ataque::LENTO,      // Fervent explosion (Fast)
    b,
    TipoMovimiento::VUELA           // Air
) {
}
void Fenix::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(fenix.graf, centro, ancho, alto);
}