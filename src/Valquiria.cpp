#include "Valquiria.h"
#include "Pieza.h"

Valquiria::Valquiria(Bando b) : Pieza(
    Ataque::MODERADO,              // Moderate
    Vida::MODERADA,                // Average
    Velocidad::NORMAL,             // Normal
    Cadencia::PROMEDIO,            // Average
    Velocidad_ataque::LENTO,       // Spear (Slow)
    b,
    TipoMovimiento::VUELA           // Air
) {
}
void Valquiria::dibuja() {}