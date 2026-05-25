#include "Basilisco.h"
#include "Pieza.h"

Basilisco::Basilisco(Bando b) : Pieza(
    Ataque::ALTO,                  
    Vida::CORTA,                   
    Velocidad::NORMAL,             
    Cadencia::RAPIDA,           
    Velocidad_ataque::RAPIDO,   
    Rango::CORTO,
    b,                             
    TipoMovimiento::CAMINA         
) {
}
void Basilisco::dibuja(const Vector2D& centro, double ancho, double alto) const
{
}