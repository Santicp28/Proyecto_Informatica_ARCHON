#include "Fenix.h"
#include "Pieza.h"

Fenix::Fenix(std::string nombre, Bando b) : Pieza(
    nombre,
    Ataque::ALTO,                  
    Vida_maxima::ALTA,                    
    Velocidad::NORMAL,             
    Cadencia::LENTA,            
    Velocidad_ataque::LENTO,      
	Rango::LARGO,
    b,
    TipoMovimiento::VUELA           
) {
    grito = new GritoArea(80.0,1.0);
}
void Fenix::dibuja(const Renderer& renderer,const Vector2D& centro, double ancho, double alto) const {
    renderer.dibujaSprite(fenix.graf, centro, ancho, alto);
}