#include "Hechicero.h"
#include "Pieza.h"


Hechicero::Hechicero(std::string nombre, Bando b) : Pieza(
    nombre,
    TipoPieza::HECHICERO,
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
