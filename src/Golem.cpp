#include "Golem.h"
#include "Pieza.h"

Golem::Golem(std::string nombre, Bando b) : Pieza(
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
void Golem::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(golem.graf, centro, ancho, alto);
}