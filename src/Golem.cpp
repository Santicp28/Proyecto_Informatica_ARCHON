#include "Golem.h"
#include "Pieza.h"

Golem::Golem(Bando b) : Pieza(
    Ataque::ALTO,               
    Vida::ALTA,              
    Velocidad::BAJA,         
    Cadencia::LENTA,      
    Velocidad_ataque::LENTO,  
	Rango::CORTO,
    b,
    TipoMovimiento::CAMINA    
) {
}
void Golem::dibuja(const Vector2D& centro, double ancho, double alto) const
{

}