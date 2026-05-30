#include "Mago.h"
#include "Pieza.h"


Mago::Mago(std::string nombre, Bando b) : Pieza(
    nombre,
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
void Mago::dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaOvalo(contenedorSprites.spriteMago.spriteCuerpo, centro, Config::magenta, ancho, alto);
}
