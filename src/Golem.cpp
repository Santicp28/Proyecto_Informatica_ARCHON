#include "Golem.h"
#include "Pieza.h"

Golem::Golem(std::string nombre, TipoPieza tipo, Bando b) : Pieza(
    nombre,
    tipo,
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
