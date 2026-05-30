#include "Banshee.h"
#include "Pieza.h"

Banshee::Banshee(std::string nombre, Bando b) : Pieza(
    nombre,
    Ataque::MODERADO,              
    Vida_maxima::MODERADA,                
    Velocidad::NORMAL,             
    Cadencia::LENTA,            
    Velocidad_ataque::RAPIDO, 
	Rango::MEDIO,
    b,                             
    TipoMovimiento::VUELA           
) {
}
void Banshee::dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaOvalo(contenedorSprites.spriteBanshee.spriteCuerpo, centro, Config::magenta, ancho, alto);
}