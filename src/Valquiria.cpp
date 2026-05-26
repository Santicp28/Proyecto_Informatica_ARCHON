#include "Valquiria.h"
#include "Pieza.h"

Valquiria::Valquiria(Bando b) : Pieza(
    Ataque::MODERADO,    
    Vida::MODERADA,     
    Velocidad::NORMAL,  
    Cadencia::PROMEDIO,         
    Velocidad_ataque::LENTO,   
    Rango::CORTO,
    b,
    TipoMovimiento::VUELA     
) {
}
void Valquiria::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(valquiria.graf, centro, ancho, alto);
}