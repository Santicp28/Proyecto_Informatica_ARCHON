#include "Arquero.h"
#include "Pieza.h"

Arquero::Arquero(std::string nombre, TipoPieza tipo, Bando b) : Pieza(
    nombre,
    tipo,
    Ataque::BAJO,                   
    Vida_maxima::CORTA,                    
    Velocidad::NORMAL,              
    Cadencia::PROMEDIO,             
    Velocidad_ataque::NORMAL,       
	Rango::CORTO,                   
    b,                              
    TipoMovimiento::CAMINA          
) {
}
void Arquero::dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaOvalo(contenedorSprites.spriteArquero.spriteCuerpo,centro,Config::magenta, ancho, alto);
}
