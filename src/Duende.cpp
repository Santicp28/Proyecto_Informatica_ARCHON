#include "Duende.h"
#include "Pieza.h"

Duende::Duende(std::string nombre, Bando b) : Pieza(
    nombre,
    Ataque::BAJO,                  
    Vida_maxima::CORTA,                   
    Velocidad::NORMAL,             
    Cadencia::MUYRAPIDA,           
    Velocidad_ataque::INSTANTANEO, 
	Rango::CORTO,
    b,
    TipoMovimiento::CAMINA         
) {
    golpe = new GolpeAtaque();
}
void Duende::dibuja(const Renderer& renderer,const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(duende.graf, centro, ancho, alto);
}