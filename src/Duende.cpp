#include "Duende.h"
#include "Pieza.h"

Duende::Duende(std::string nombre, TipoPieza tipo, Bando b) : Pieza(
    nombre,
    tipo,
    Ataque::BAJO,                  
    Vida_maxima::CORTA,                   
    Velocidad::NORMAL,             
    Cadencia::MUYRAPIDA,           
    Velocidad_ataque::INSTANTANEO, 
	Rango::CORTO,
    b,
    TipoMovimiento::CAMINA         
) {
    golpe = new GolpeAtaque(duende.grafAtaque, 80.0);
}
}
void Duende::dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaOvalo(contenedorSprites.spriteDuende.spriteCuerpo, centro, Config::magenta, ancho, alto);
}