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
void Arquero::dibuja(const Renderer& renderer){
    renderer.dibujaSprite(archer.graf, /* centro */, /* ancho */, /* alto */);
}
