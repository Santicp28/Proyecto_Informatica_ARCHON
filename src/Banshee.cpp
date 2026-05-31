#include "Banshee.h"
#include "Pieza.h"

Banshee::Banshee(std::string nombre, TipoPieza tipo, Bando b) : Pieza(
    nombre,
    tipo,
    Ataque::MODERADO,              
    Vida_maxima::MODERADA,                
    Velocidad::NORMAL,             
    Cadencia::LENTA,            
    Velocidad_ataque::RAPIDO, 
	Rango::MEDIO,
    b,                             
    TipoMovimiento::VUELA           
) {
    grito = new GritoArea();
}
void Banshee::dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaOvalo(contenedorSprites.spriteBanshee.spriteCuerpo, centro, Config::magenta, ancho, alto);
}