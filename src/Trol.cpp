#include "Trol.h"
#include "Pieza.h"

Trol::Trol(Bando b) : Pieza(
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
void Trol::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(trol.graf, centro, ancho, alto);
}
