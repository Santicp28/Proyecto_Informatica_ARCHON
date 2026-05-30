#include "Djinni.h"
#include "Pieza.h"

Djinni::Djinni(std::string nombre, Bando b) : Pieza(
    nombre,
    Ataque::MODERADO,              
    Vida_maxima::ALTA,                
    Velocidad::NORMAL,             
    Cadencia::PROMEDIO,            
    Velocidad_ataque::NORMAL,      
    Rango::MEDIO,
    b,
    TipoMovimiento::VUELA   
) {
}
void Djinni::dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaOvalo(contenedorSprites.spriteDjinni.spriteCuerpo, centro, Config::magenta, ancho, alto);
}