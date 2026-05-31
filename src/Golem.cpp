#include "Golem.h"
#include "Pieza.h"

Golem::Golem(std::string nombre, Bando b) : Pieza(
    nombre,
	TipoPieza::GOLEM,
    Ataque::ALTO,               
    Vida_maxima::ALTA,              
    Velocidad::BAJA,         
    Cadencia::LENTA,      
    Velocidad_ataque::LENTO,  
	Rango::CORTO,
    b,
    TipoMovimiento::CAMINA    
) {
}
