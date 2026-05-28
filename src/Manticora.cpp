#include "Manticora.h"
#include "Pieza.h"

Manticora::Manticora(Bando b) : Pieza(
    Ataque::BAJO,           
    Vida_maxima::MODERADA,          
    Velocidad::NORMAL,           
    Cadencia::PROMEDIO,       
    Velocidad_ataque::LENTO,   
	Rango::CORTO,
    b,
    TipoMovimiento::CAMINA   
) {
}
void Manticora::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(manticora.graf, centro, ancho, alto);
}