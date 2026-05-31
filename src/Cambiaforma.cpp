#include "Cambiaforma.h"
#include "Pieza.h"

Cambiaforma::Cambiaforma(std::string nombre,Bando b) : Pieza(
    nombre,
    TipoPieza::CAMBIAFORMA,
    Ataque::VARIABLE,              
    Vida_maxima::VARIABLE,                
    Velocidad::VARIABLE,           
    Cadencia::VARIABLE,            
    Velocidad_ataque::VARIABLE,    
	Rango::LARGO,
    b,                             
    TipoMovimiento::VUELA           
) {
}
