#include "Caballero.h"
#include "Pieza.h"

Caballero::Caballero(Bando b) : Pieza(
    Ataque::BAJO,                  
    Vida::CORTA,                
    Velocidad::NORMAL,             
    Cadencia::MUYRAPIDA,           
    Velocidad_ataque::INSTANTANEO, 
	Rango::CORTO,
    b,                             
    TipoMovimiento::CAMINA         
) {
}
void Caballero::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(caballero.graf, centro, ancho, alto);
}