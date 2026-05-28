#include "Valquiria.h"
#include "Pieza.h"

Valquiria::Valquiria(std::string nombre, Bando b) : Pieza(
    nombre,
    Ataque::MODERADO,    
    Vida_maxima::MODERADA,     
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