#include "Djinni.h"
#include "Pieza.h"

Djinni::Djinni(Bando b) : Pieza(
    Ataque::MODERADO,              // Moderate
    Vida::ALTA,                // Average
    Velocidad::NORMAL,             // Normal (Fast base)
    Cadencia::PROMEDIO,            // Average
    Velocidad_ataque::NORMAL,      // Twister (Middle)
    b,
    TipoMovimiento::VUELA           // Air
) {
}
void Djinni::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(djinni.graf, centro, ancho, alto);
}