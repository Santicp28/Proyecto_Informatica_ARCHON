#include "Fenix.h"
#include "Pieza.h"

Fenix::Fenix(Bando b) : Pieza(
    Ataque::ALTO,                  
    Vida_maxima::ALTA,                    
    Velocidad::NORMAL,             
    Cadencia::LENTA,            
    Velocidad_ataque::LENTO,      
	Rango::LARGO,
    b,
    TipoMovimiento::VUELA           
) {
}
void Fenix::dibuja(const Renderer& renderer,const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(fenix.graf, centro, ancho, alto);
}