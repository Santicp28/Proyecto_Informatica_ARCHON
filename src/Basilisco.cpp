#include "Basilisco.h"
#include "Pieza.h"

Basilisco::Basilisco(std::string nombre, Bando b) : Pieza(
    nombre,
    TipoPieza::BASILISCO,
    Ataque::ALTO,                  
    Vida_maxima::CORTA,                   
    Velocidad::NORMAL,             
    Cadencia::RAPIDA,           
    Velocidad_ataque::RAPIDO,   
    Rango::CORTO,
    b,                             
    TipoMovimiento::CAMINA         
) {
}

