#include "Banshee.h"
#include "Pieza.h"

Banshee::Banshee(Bando b) : Pieza(
    Ataque::MODERADO,              // Moderate
    Vida::MODERADA,                // Average
    Velocidad::NORMAL,             // Normal
    Cadencia::LENTA,            // Average
    Velocidad_ataque::RAPIDO,      // Keen
    b,                             // Bando dinámico
    TipoMovimiento::VUELA
) {
}
void Banshee::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(banshee.graf, centro, ancho, alto);
}