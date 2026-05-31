#include "Dragon.h"
#include "Pieza.h"

Dragon::Dragon(std::string nombre,Bando b) : Pieza(
    nombre,
    TipoPieza::DRAGON,
    Ataque::MUYALTO,               
    Vida_maxima::MUYALTA,                 
    Velocidad::NORMAL,             
    Cadencia::LENTA,               
    Velocidad_ataque::NORMAL,      
	Rango::MEDIO,
    b,
    TipoMovimiento::VUELA           
) {
}

