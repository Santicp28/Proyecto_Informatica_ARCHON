#include "Manticora.h"
#include "Pieza.h"

Manticora::Manticora(Bando b) : Pieza(
    Ataque::BAJO,           
    Vida::MODERADA,          
    Velocidad::NORMAL,           
    Cadencia::PROMEDIO,       
    Velocidad_ataque::LENTO,   
	Rango::CORTO,
    b,
    TipoMovimiento::CAMINA   
) {
}
void Manticora::dibuja(const Vector2D& centro, double ancho, double alto) const
{

}