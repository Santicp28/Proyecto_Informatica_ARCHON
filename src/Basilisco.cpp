#include "Basilisco.h"
#include "Pieza.h"

Basilisco::Basilisco(std::string nombre, Bando b) : Pieza(
    nombre,
    Ataque::ALTO,                  
    Vida_maxima::CORTA,                   
    Velocidad::NORMAL,             
    Cadencia::RAPIDA,           
    Velocidad_ataque::RAPIDO,   
    Rango::CORTO,
    b,                             
    TipoMovimiento::CAMINA         
) {
}
void Basilisco::dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaOvalo(contenedorSprites.spriteBasilisco.spriteCuerpo, centro,Config::magenta, ancho, alto);
}
