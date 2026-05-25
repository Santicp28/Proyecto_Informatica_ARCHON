#include "Manticora.h"
#include "Pieza.h"

Manticora::Manticora(Bando b) : Pieza(
    Ataque::BAJO,                  // Low
    Vida::MODERADA,                // Average
    Velocidad::NORMAL,             // Normal
    Cadencia::PROMEDIO,            // Average
    Velocidad_ataque::LENTO,      // Spikes (Slow-Normal)
    b,
    TipoMovimiento::CAMINA         // Ground
) {
}
void Manticora::dibuja() {}