#include "Arquero.h"
#include "Pieza.h"

Arquero::Arquero(std::string nombre, Bando b) : Pieza(
    nombre,
    TipoPieza::ARQUERO,
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

