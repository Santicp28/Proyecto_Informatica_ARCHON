#include "Mago.h"
#include "Pieza.h"

Mago::Mago(Bando b) : Pieza(
    Ataque::ALTO,               
    Vida::MODERADA,        
    Velocidad::NORMAL,  
    Cadencia::PROMEDIO,    
    Velocidad_ataque::NORMAL,
	Rango::CORTO,
    b,
    TipoMovimiento::TELETRANSPORTE 
) {
}
void Mago::dibuja(const Renderer& renderer, const char* rutaPNG, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(mago.graf, centro, ancho, alto);
}
