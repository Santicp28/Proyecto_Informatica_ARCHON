#include "Trol.h"
#include "Pieza.h"

Trol::Trol(std::string nombre, Bando b) : Pieza(
    nombre,
    Ataque::ALTO,                
    Vida_maxima::ALTA,      
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
