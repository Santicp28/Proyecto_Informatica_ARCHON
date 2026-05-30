#include "Manticora.h"
#include "Pieza.h"

Manticora::Manticora(std::string nombre, Bando b) : Pieza(
    nombre,
	TipoPieza::MANTICORA,
    Ataque::BAJO,           
    Vida_maxima::MODERADA,          
    Velocidad::NORMAL,           
    Cadencia::PROMEDIO,       
    Velocidad_ataque::LENTO,   
	Rango::CORTO,
    b,
    TipoMovimiento::CAMINA   
) {
}
