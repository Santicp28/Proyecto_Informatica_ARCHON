#include "Valquiria.h"
#include "Pieza.h"

Valquiria::Valquiria(std::string nombre, Bando b) : Pieza(
    nombre,
    TipoPieza::VALQUIRIA,
    Ataque::MODERADO,    
    Vida_maxima::MODERADA,     
    Velocidad::NORMAL,  
    Cadencia::PROMEDIO,         
    Velocidad_ataque::LENTO,   
    Rango::CORTO,
    b,
    TipoMovimiento::VUELA     
) {
}
