#include "Boton.h"
void Boton::dibuja(const Renderer& renderer, const Vector2D& posicion, const Vector2D& size) const
{
    renderer.dibujaCuadrado(posicion, colorArea, size * escala);
    renderer.dibujaContornoCuadrado(posicion, colorPerimetro, size * escala);
	renderer.dibujaTexto(texto, posicion, colorTexto, size.y*escala*0.4);
}

void Boton::cambiarEstado()
{
    seleccionado = !seleccionado;   
    if (seleccionado ==true) {
        
        colorArea = { 0.3f, 0.5f, 0.9f };
        colorPerimetro = { 1.0f,1.0f,0.0f };
        escala = 1.2;
    }
    else {
        colorArea = { 0.2f, 0.25f, 0.4f };
        colorPerimetro = { 1.0f,1.0f,1.0f };
        escala = 1.0;
    }
}
