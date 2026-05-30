#include "Arquero.h"
#include "Pieza.h"

Arquero::Arquero(std::string nombre, TipoPieza tipo, Bando b) : Pieza(
    nombre,
    tipo,
    Ataque::BAJO,                   
    Vida_maxima::CORTA,                    
    Velocidad::NORMAL,              
    Cadencia::PROMEDIO,             
    Velocidad_ataque::NORMAL,       
	Rango::CORTO,                   
    b,                              
    TipoMovimiento::CAMINA          
) {
}

