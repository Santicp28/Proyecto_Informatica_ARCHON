#include "Fenix.h"
#include "Pieza.h"

Fenix::Fenix(Bando b) : Pieza(
    Ataque::ALTO,                  // High
    Vida::ALTA,                    // Long
    Velocidad::NORMAL,             // Normal
    Cadencia::LENTA,            // Average
    Velocidad_ataque::LENTO,      // Fervent explosion (Fast)
    b,
    TipoMovimiento::VUELA           // Air
) {
}
void Fenix::dibuja() {}