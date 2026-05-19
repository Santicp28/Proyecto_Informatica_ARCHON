#include "Casilla.h"
#include "DesacopleGrafico.h"

void Casilla::dibuja() const
{
	DesacopleGrafico::setCuadrado(posicion2D, longitud);
    // 2. Dibujar el borde con un pequeño offset en Z para evitar parpadeo
    glColor3f(1.0f, 0.0f, 0.0f); // Gris oscuro para bordes elegantes
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(x, y, 0.01f);
    glVertex3f(x + sizeCasillas, y, 0.01f);
    glVertex3f(x + sizeCasillas, y + sizeCasillas, 0.01f);
    glVertex3f(x, y + sizeCasillas, 0.01f);
    glEnd();
}

void Casilla::setTipo(const TipoCasilla& nuevoTipo)
{
	tipo = nuevoTipo;
    switch (tipo)
    {
    case TipoCasilla::OSCURA:
        DesacopleGrafico::setColor({ 0.f, 0.f, 0.f });
            break;

    case TipoCasilla::CLARA: 
        DesacopleGrafico::setColor({ 1.f, 1.f, 1.f });
            break;
    case TipoCasilla::OSCILANTE:
        DesacopleGrafico::setColor({ 1.f, 1.f, 1.f });
            break;
    case TipoCasilla::PODER:
        DesacopleGrafico::setColor({ 1.f, 1.f, 0.f });
            break;
    }
}

void Casilla::setPosicion(const Vector2D& posicionPrimera, const unsigned int f, const unsigned int c)
{
	posicionMatriz= {f,c};
	posicion2D = { posicionPrimera.x + posicionMatriz.columna * longitud, posicionPrimera.y - posicionMatriz.fila * longitud };
}
