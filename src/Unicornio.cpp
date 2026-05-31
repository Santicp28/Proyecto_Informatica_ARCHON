#include "Unicornio.h"
#include "Pieza.h"

Unicornio::Unicornio(std::string nombre, Bando b) : Pieza(
    nombre,
	TipoPieza::UNICORNIO,
    Ataque::MODERADO,      
    Vida_maxima::MODERADA,        
    Velocidad::NORMAL,      
    Cadencia::LENTA,       
    Velocidad_ataque::RAPIDO,   
	Rango::MEDIO,
    b,
    TipoMovimiento::CAMINA     
) {
}
