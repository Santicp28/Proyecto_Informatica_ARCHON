#include "Trol.h"
#include "Pieza.h"

Trol::Trol(std::string nombre, Bando b) : Pieza(
    nombre,
    TipoPieza::TROL,
    Ataque::ALTO,                
    Vida_maxima::ALTA,      
    Velocidad::BAJA,        
    Cadencia::LENTA, 
    Velocidad_ataque::LENTO,  
	Rango::CORTO,
    b,
    TipoMovimiento::CAMINA      
) {
}
