#include "Basilisco.h"
#include "Pieza.h"

Basilisco::Basilisco(Bando b) : Pieza(
    Ataque::ALTO,                  
    Vida_maxima::CORTA,                   
    Velocidad::NORMAL,             
    Cadencia::RAPIDA,           
    Velocidad_ataque::RAPIDO,   
    Rango::CORTO,
    b,                             
    TipoMovimiento::CAMINA         
) {
}
void Basilisco::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(basilisco.graf, centro, ancho, alto);
}
