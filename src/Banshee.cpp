#include "Banshee.h"
#include "Pieza.h"

Banshee::Banshee(std::string nombre,Bando b) : Pieza(
    nombre,
    TipoPieza::BANSHEE,
    Ataque::MODERADO,              
    Vida_maxima::MODERADA,                
    Velocidad::NORMAL,             
    Cadencia::LENTA,            
    Velocidad_ataque::RAPIDO, 
	Rango::MEDIO,
    b,                             
    TipoMovimiento::VUELA           
) {
    grito = new GritoArea();
}
