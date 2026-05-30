#include "Dragon.h"
#include "Pieza.h"

Dragon::Dragon(std::string nombre, TipoPieza tipo, Bando b) : Pieza(
    nombre,
    tipo,
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

