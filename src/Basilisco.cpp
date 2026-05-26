#include "Basilisco.h"
#include "Pieza.h"

Basilisco::Basilisco(Bando b) : Pieza(
    Ataque::ALTO,                  // High
    Vida::CORTA,                   // Short
    Velocidad::NORMAL,             // Normal
    Cadencia::RAPIDA,           // Short
    Velocidad_ataque::RAPIDO,      // Eye laser
    b,                             // Bando dinámico
    TipoMovimiento::CAMINA         // Ground
) {
}
void Basilisco::dibuja(const Renderer& renderer, const char* rutaPNG, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(basilisco.graf, centro, ancho, alto);
}
