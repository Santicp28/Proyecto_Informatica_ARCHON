#include "Cambiaforma.h"
#include "Pieza.h"

Cambiaforma::Cambiaforma(std::string nombre, TipoPieza tipo, Bando b) : Pieza(
    nombre,
    tipo,
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
void Cambiaforma::dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaOvalo(contenedorSprites.spriteCambiaforma.spriteCuerpo, centro, Config::magenta, ancho, alto);
}