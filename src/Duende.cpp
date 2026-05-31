#include "Duende.h"
#include "Pieza.h"

Duende::Duende(std::string nombre,Bando b) : Pieza(
    nombre,
	TipoPieza::DUENDE,
    Ataque::BAJO,                  
    Vida_maxima::CORTA,                   
    Velocidad::NORMAL,             
    Cadencia::MUYRAPIDA,           
    Velocidad_ataque::INSTANTANEO, 
	Rango::CORTO,
    b,
    TipoMovimiento::CAMINA         
) {
    golpe = new GolpeAtaque(duende.grafAtaque, 80.0);
}
