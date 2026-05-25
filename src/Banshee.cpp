#include "Banshee.h"
#include "Pieza.h"

Banshee::Banshee(Bando b) : Pieza(
    Ataque::MODERADO,              
    Vida::MODERADA,                
    Velocidad::NORMAL,             
    Cadencia::LENTA,            
    Velocidad_ataque::RAPIDO, 
	Rango::MEDIO,
    b,                             
    TipoMovimiento::VUELA           
) {
}
void Banshee::dibuja(const Vector2D& centro, double ancho, double alto) const
{
}
