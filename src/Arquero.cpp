#include "Arquero.h"
#include "Pieza.h"

Arquero::Arquero(std::string nombre, Bando b) : Pieza(
    nombre,
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
void Arquero::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(arquero.graf,centro, ancho, alto);
}
