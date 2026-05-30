#include "Mago.h"
#include "Pieza.h"


Mago::Mago(std::string nombre, Bando b) : Pieza(
    nombre,
	TipoPieza::MAGO,    
    Ataque::ALTO,               
    Vida_maxima::MODERADA,        
    Velocidad::NORMAL,  
    Cadencia::PROMEDIO,    
    Velocidad_ataque::NORMAL,
	Rango::CORTO,
    b,
    TipoMovimiento::TELETRANSPORTE 
) {
}

