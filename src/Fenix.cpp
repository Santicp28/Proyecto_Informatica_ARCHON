#include "Fenix.h"
#include "Pieza.h"

Fenix::Fenix(std::string nombre, Bando b) : Pieza(
    nombre,
    TipoPieza::FENIX,
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
