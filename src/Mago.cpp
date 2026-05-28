#include "Mago.h"
#include "Pieza.h"
#include "TiposPiezas.h"

Mago::Mago(Bando b) : Pieza(
    Ataque::ALTO,               
    Vida_maxima::MODERADA,        
    Velocidad::NORMAL,  
    Cadencia::PROMEDIO,    
    Velocidad_ataque::NORMAL,
	Rango::CORTO,
    b,
    TipoMovimiento::TELETRANSPORTE 
) {
}
void Mago::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(mago.graf, centro, ancho, alto);
}
