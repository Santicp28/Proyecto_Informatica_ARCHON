#include "Mago.h"
#include "Pieza.h"


Mago::Mago(std::string nombre, TipoPieza tipo, Bando b) : Pieza(
    nombre,
    tipo,
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

