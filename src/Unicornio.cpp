#include "Unicornio.h"
#include "Pieza.h"

Unicornio::Unicornio(std::string nombre, TipoPieza tipo, Bando b) : Pieza(
    nombre,
    tipo,
    Ataque::MODERADO,      
    Vida_maxima::MODERADA,        
    Velocidad::NORMAL,      
    Cadencia::LENTA,       
    Velocidad_ataque::RAPIDO,   
	Rango::MEDIO,
    b,
    TipoMovimiento::CAMINA     
) {
}
void Unicornio::dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaOvalo(contenedorSprites.spriteUnicornio.spriteCuerpo, centro, Config::magenta, ancho, alto);
}