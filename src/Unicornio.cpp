#include "Unicornio.h"
#include "Pieza.h"

Unicornio::Unicornio(std::string nombre, TipoPieza tipo, Bando b) : Pieza(
    nombre,
    tipo,
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
