#include "Banshee.h"
#include "Pieza.h"

Banshee::Banshee(Bando b) : Pieza(
    Ataque::MODERADO,              
    Vida_maxima::MODERADA,                
    Velocidad::NORMAL,             
    Cadencia::LENTA,            
    Velocidad_ataque::RAPIDO, 
	Rango::MEDIO,
    b,                             
    TipoMovimiento::VUELA           
) {
}
void Banshee::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(banshee.graf, centro, ancho, alto);
}