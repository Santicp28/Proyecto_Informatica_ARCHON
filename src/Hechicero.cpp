#include "Hechicero.h"
#include "Pieza.h"


Hechicero::Hechicero(Bando b) : Pieza(
    Ataque::MODERADO,              
    Vida::MODERADA,                
    Velocidad::NORMAL,             
    Cadencia::PROMEDIO,            
    Velocidad_ataque::RAPIDO,    
	Rango::CORTO,
    b,
    TipoMovimiento::TELETRANSPORTE 
) {
}
void Hechicero::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(hechicero.graf, centro, ancho, alto);
}
