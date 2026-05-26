#include "Dragon.h"
#include "Pieza.h"

Dragon::Dragon(Bando b) : Pieza(
    Ataque::MUYALTO,               
    Vida::MUYALTA,                 
    Velocidad::NORMAL,             
    Cadencia::LENTA,               
    Velocidad_ataque::NORMAL,      
	Rango::MEDIO,
    b,
    TipoMovimiento::VUELA           
) {
}
void Dragon::dibuja(const Renderer& renderer, const char* rutaPNG, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(dragon.graf, centro, ancho, alto);
}
