#include "Dragon.h"
#include "Pieza.h"

Dragon::Dragon(std::string nombre, Bando b) : Pieza(
    nombre,
    Ataque::MUYALTO,               
    Vida_maxima::MUYALTA,                 
    Velocidad::NORMAL,             
    Cadencia::LENTA,               
    Velocidad_ataque::NORMAL,      
	Rango::MEDIO,
    b,
    TipoMovimiento::VUELA           
) {
}
void Dragon::dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaOvalo(contenedorSprites.spriteDragon.spriteCuerpo, centro, Config::magenta, ancho, alto);
}
