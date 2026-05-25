#include "Duende.h"
#include "Pieza.h"

Duende::Duende(Bando b) : Pieza(
    Ataque::BAJO,                  // Low
    Vida::CORTA,                   // Short
    Velocidad::NORMAL,             // Normal
    Cadencia::MUYRAPIDA,           // Very short
    Velocidad_ataque::INSTANTANEO, // Club (Melee)
    b,
    TipoMovimiento::CAMINA         // Ground
) {
}
void Duende::dibuja() {}