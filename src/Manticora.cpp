#include "Manticora.h"
#include "Pieza.h"

Manticora::Manticora(std::string nombre, Bando b) : Pieza(
    nombre,
    Ataque::BAJO,           
    Vida_maxima::MODERADA,          
    Velocidad::NORMAL,           
    Cadencia::PROMEDIO,       
    Velocidad_ataque::LENTO,   
	Rango::CORTO,
    b,
    TipoMovimiento::CAMINA   
) {
}
void Manticora::dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaOvalo(contenedorSprites.spriteManticora.spriteCuerpo, centro, Config::magenta, ancho, alto);
}