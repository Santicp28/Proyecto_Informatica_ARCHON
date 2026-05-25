#include "Mago.h"
#include "Pieza.h"

Mago::Mago(Bando b) : Pieza(
    Ataque::ALTO,               
    Vida::MODERADA,        
    Velocidad::NORMAL,  
    Cadencia::PROMEDIO,    
    Velocidad_ataque::NORMAL,
	Rango::CORTO,
    b,
    TipoMovimiento::TELETRANSPORTE 
) {
}
void Mago::dibuja(const Vector2D& centro, double ancho, double alto) const
{

}
