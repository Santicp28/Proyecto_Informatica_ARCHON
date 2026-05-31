#include "Valquiria.h"
#include "Pieza.h"

Valquiria::Valquiria(std::string nombre, TipoPieza tipo, Bando b) : Pieza(
    nombre,
    tipo,
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
void Valquiria::dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaOvalo(contenedorSprites.spriteValquiria.spriteCuerpo, centro, Config::magenta, ancho, alto);
}