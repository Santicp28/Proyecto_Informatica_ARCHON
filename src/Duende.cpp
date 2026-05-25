#include "Duende.h"
#include "Pieza.h"

Duende::Duende(Bando b) : Pieza(
    Ataque::BAJO,                  
    Vida::CORTA,                   
    Velocidad::NORMAL,             
    Cadencia::MUYRAPIDA,           
    Velocidad_ataque::INSTANTANEO, 
	Rango::CORTO,
    b,
    TipoMovimiento::CAMINA         
) {
}
void Duende::dibuja(const Vector2D& centro, double ancho, double alto) const
{

}