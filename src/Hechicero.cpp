#include "Hechicero.h"
#include "Pieza.h"


Hechicero::Hechicero(std::string nombre, TipoPieza tipo, Bando b) : Pieza(
    nombre,
    tipo,
    Ataque::MODERADO,              
    Vida_maxima::MODERADA,                
    Velocidad::NORMAL,             
    Cadencia::PROMEDIO,            
    Velocidad_ataque::RAPIDO,    
	Rango::CORTO,
    b,
    TipoMovimiento::TELETRANSPORTE 
) {
}
