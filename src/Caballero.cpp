#include "Caballero.h"
#include "Pieza.h"

Caballero::Caballero(std::string nombre, Bando b) : Pieza(
    nombre,
    TipoPieza::CABALLERO,
    Ataque::BAJO,                  
    Vida_maxima::CORTA,                
    Velocidad::NORMAL,             
    Cadencia::MUYRAPIDA,           
    Velocidad_ataque::INSTANTANEO, 
	Rango::CORTO,
    b,                             
    TipoMovimiento::CAMINA         
) {
    golpe = new GolpeAtaque(caballero.grafAtaque, 80.0);
}
