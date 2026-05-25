#include "Arquero.h"
#include "Pieza.h"

Arquero::Arquero(Bando b) : Pieza(
    Ataque::BAJO,                   
    Vida::CORTA,                    
    Velocidad::NORMAL,              
    Cadencia::PROMEDIO,             
    Velocidad_ataque::NORMAL,       
	Rango::CORTO,                   
    b,                              
    TipoMovimiento::CAMINA          
) {
}

void Arquero::dibuja(const Vector2D& centro, double ancho, double alto) const {
    //a
}



    