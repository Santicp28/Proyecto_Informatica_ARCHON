#include "Golem.h"
#include "Pieza.h"

Golem::Golem(Bando b) : Pieza(
    Ataque::ALTO,                  // High
    Vida::ALTA,                    // Long
    Velocidad::BAJA,               // Slow
    Cadencia::LENTA,               // Long
    Velocidad_ataque::LENTO,       // Stone chippings (Slow)
    b,
    TipoMovimiento::CAMINA         // Ground
) {
}
void Golem::dibuja() {}