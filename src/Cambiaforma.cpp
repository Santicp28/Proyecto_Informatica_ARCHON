#include "Cambiaforma.h"
#include "Pieza.h"

Cambiaforma::Cambiaforma(Bando b) : Pieza(
    Ataque::VARIABLE,              // Variable
    Vida::VARIABLE,                // Variable
    Velocidad::VARIABLE,           // Variable
    Cadencia::VARIABLE,            // Variable
    Velocidad_ataque::VARIABLE,    // Variable
    b,                             // Bando dinámico
    TipoMovimiento::VUELA           // Air
) {
}
void Cambiaforma::dibuja(const Renderer& renderer, const char* rutaPNG, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(cambiaforma.graf, centro, ancho, alto);
}