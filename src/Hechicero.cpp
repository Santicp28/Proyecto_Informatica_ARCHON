#include "Hechicero.h"
#include "Pieza.h"


Hechicero::Hechicero(std::string nombre, TipoPieza tipo, Bando b) : Pieza(
    nombre,
    tipo,
    Ataque::MODERADO,              
    Vida_maxima::MODERADA,                
    Velocidad::NORMAL,             
    Cadencia::PROMEDIO,            
    Velocidad_ataque::RAPIDO,    
	Rango::CORTO,
    b,
    TipoMovimiento::TELETRANSPORTE 
) {
}
void Hechicero::dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaOvalo(contenedorSprites.spriteHechicero.spriteCuerpo, centro, Config::magenta, ancho, alto);
}
