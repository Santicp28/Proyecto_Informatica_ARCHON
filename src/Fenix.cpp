#include "Fenix.h"
#include "Pieza.h"

Fenix::Fenix(std::string nombre, TipoPieza tipo, Bando b) : Pieza(
    nombre,
    tipo,
    Ataque::ALTO,                  
    Vida_maxima::ALTA,                    
    Velocidad::NORMAL,             
    Cadencia::LENTA,            
    Velocidad_ataque::LENTO,      
	Rango::LARGO,
    b,
    TipoMovimiento::VUELA           
) {
    grito = new GritoArea(80.0, 1.0, fenix.grafAtaque);
}
