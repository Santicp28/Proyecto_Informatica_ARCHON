#include "Unicornio.h"
#include "Pieza.h"

Unicornio::Unicornio(Bando b) : Pieza(
    Ataque::MODERADO,      
    Vida::MODERADA,        
    Velocidad::NORMAL,      
    Cadencia::LENTA,       
    Velocidad_ataque::RAPIDO,   
	Rango::MEDIO,
    b,
    TipoMovimiento::CAMINA     
) {
}
void Unicornio::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(unicornio.graf, centro, ancho, alto);
}