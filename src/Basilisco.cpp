#include "Basilisco.h"
#include "Pieza.h"

Basilisco::Basilisco(std::string nombre, TipoPieza tipo, Bando b) : Pieza(
    nombre,
    tipo,
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

