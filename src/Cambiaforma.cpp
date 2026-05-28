#include "Cambiaforma.h"
#include "Pieza.h"

Cambiaforma::Cambiaforma(Bando b) : Pieza(
    Ataque::VARIABLE,              
    Vida_maxima::VARIABLE,                
    Velocidad::VARIABLE,           
    Cadencia::VARIABLE,            
    Velocidad_ataque::VARIABLE,    
	Rango::LARGO,
    b,                             
    TipoMovimiento::VUELA           
) {
}
void Cambiaforma::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(cambiaforma.graf, centro, ancho, alto);
}