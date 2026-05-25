#include "Caballero.h"
#include "Pieza.h"

Caballero::Caballero(Bando b) : Pieza(
    Ataque::BAJO,                  // High
    Vida::CORTA,                // Very short
    Velocidad::NORMAL,             // Normal
    Cadencia::MUYRAPIDA,           // Very short
    Velocidad_ataque::INSTANTANEO, // Sword
    b,                             // Bando dinámico
    TipoMovimiento::CAMINA         // Ground
) {
}
void Caballero::dibuja()
{
}