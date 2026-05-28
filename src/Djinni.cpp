#include "Djinni.h"
#include "Pieza.h"

Djinni::Djinni(Bando b) : Pieza(
    Ataque::MODERADO,              
    Vida_maxima::ALTA,                
    Velocidad::NORMAL,             
    Cadencia::PROMEDIO,            
    Velocidad_ataque::NORMAL,      
    Rango::MEDIO,
    b,
    TipoMovimiento::VUELA   
) {
}
void Djinni::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(djinni.graf, centro, ancho, alto);
}