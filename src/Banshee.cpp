#include "Banshee.h"
#include "Pieza.h"

Banshee::Banshee(Bando b) : Pieza(
    Ataque::MODERADO,              // Moderate
    Vida::MODERADA,                // Average
    Velocidad::NORMAL,             // Normal
    Cadencia::LENTA,            // Average
    Velocidad_ataque::RAPIDO,      // Keen
    b,                             // Bando dinámico
    TipoMovimiento::VUELA           // Air
) {
}
void Banshee::dibuja()
{
}