#include "Hechicero.h"
#include "Pieza.h"

Hechicero::Hechicero(Bando b) : Pieza(
    Ataque::MODERADO,              // Moderate
    Vida::MODERADA,                // Average
    Velocidad::NORMAL,             // Normal
    Cadencia::PROMEDIO,            // Average
    Velocidad_ataque::RAPIDO,      // Light beams (Fast)
    b,
    TipoMovimiento::TELETRANSPORTE // Teleport
) {
}
void Hechicero::dibuja() {}