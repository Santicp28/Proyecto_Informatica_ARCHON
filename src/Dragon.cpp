#include "Dragon.h"
#include "Pieza.h"

Dragon::Dragon(Bando b) : Pieza(
    Ataque::MUYALTO,               // Very High
    Vida::MUYALTA,                 // Very Long
    Velocidad::NORMAL,             // Normal
    Cadencia::LENTA,               // Long
    Velocidad_ataque::NORMAL,      // Fervent breath (Middle)
    b,
    TipoMovimiento::VUELA           // Air
) {
}
void Dragon::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(dragon.graf, centro, ancho, alto);
}
