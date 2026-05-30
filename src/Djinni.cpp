#include "Djinni.h"
#include "Pieza.h"

Djinni::Djinni(std::string nombre, Bando b) : Pieza(
    nombre,
	TipoPieza::DJINNI,
    Ataque::MODERADO,              
    Vida_maxima::ALTA,                
    Velocidad::NORMAL,             
    Cadencia::PROMEDIO,            
    Velocidad_ataque::NORMAL,      
    Rango::MEDIO,
    b,
    TipoMovimiento::VUELA   
) {
}
