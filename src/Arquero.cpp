#include "Arquero.h"
#include "Pieza.h"

Arquero::Arquero(Bando b) : Pieza(
    Ataque::BAJO,                   // Low
    Vida::CORTA,                    // Short
    Velocidad::NORMAL,              // Normal
    Cadencia::PROMEDIO,             // Average
    Velocidad_ataque::NORMAL,       // Arrow
    b,                              // Bando dinámico
    TipoMovimiento::CAMINA          // Ground
) {
}
void Arquero::dibuja(const Renderer& renderer, const char* rutaPNG, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(mago.graf,centro, ancho, alto);
}
