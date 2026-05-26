#include <windows.h>
#include "ETSIDI.h"
#include "freeglut.h"
#include "Renderer.h"

void Renderer::inicializa2D(unsigned int longitud,unsigned int altura)
{
	sizeDibujo = { static_cast<double>(longitud),static_cast<double>(altura) };

	glDisable(GL_DEPTH_TEST);//No hay 3D real de profundidad, todo se dibuja en orden de renderizado
	glDisable(GL_LIGHTING);//Desactiva el sistema de iluminación de OpenGL

	glMatrixMode(GL_PROJECTION);//Cambia al modo matriz de proyección (estás definiendo “cómo se ve la cámara”, no los objetos)
	glLoadIdentity();//Resetea la matriz de proyección
	glOrtho
		(0.0, longitud,// eje x estandar (0= izda, 800= drcha)
		altura, 0.0,// eje y invertido (0= arriba, 600= abajo)
		-1.0, 1.0);//grados de profundidad

	glMatrixMode(GL_MODELVIEW);// todo lo siguiente define como se ven los objetos
}

void Renderer::dibujaCuadrado(const Vector2D& centro, const Color& color, double longitud)const
{
	longitud = longitud / 2.0;
	dibujaColor(color);	
	glBegin(GL_QUADS);

	glVertex2d(centro.x - longitud, centro.y - longitud); // abajo izquierda
	glVertex2d(centro.x + longitud, centro.y - longitud); // abajo derecha
	glVertex2d(centro.x + longitud, centro.y + longitud); // arriba derecha
	glVertex2d(centro.x - longitud, centro.y + longitud); // arriba izquierda

	glEnd();

}

void Renderer::dibujaContornoCuadrado(const Vector2D& centro, const Color& color, double longitud)const
{
	// 2. Dibujar el borde con un pequeño offset en Z para evitar parpadeo
	longitud = longitud / 2.0;
	dibujaColor(color);
	glLineWidth(2.0f);//ancho de lineas
	glBegin(GL_LINE_LOOP);
	glVertex3d(centro.x - longitud, centro.y - longitud, 0.1); // abajo izquierda
	glVertex3d(centro.x + longitud, centro.y - longitud, 0.1); // abajo derecha
	glVertex3d(centro.x + longitud, centro.y + longitud, 0.1); // arriba derecha
	glVertex3d(centro.x - longitud, centro.y + longitud, 0.1); // arriba izquierda
	glEnd();
}

void Renderer::dibujaSprite(const char* rutaPNG, const Vector2D& centro, double ancho, double alto) const {
	ETSIDI::Sprite sprite(rutaPNG, (double)(centro.x - ancho / 2), (double)(centro.y - alto / 2), (double)ancho, (double)alto);

	glPushMatrix();

	glTranslated(centro.x, centro.y, 0.0);
	glScaled(1.0, -1.0, 1.0);
	glTranslated(-centro.x, -centro.y, 0.0);

	sprite.draw();

	glPopMatrix();
}

void Renderer::dibujaTexto(const char* texto, const Vector2D& pos, double r, double g, double b, int size) const {
	ETSIDI::setTextColor(r, g, b);
	ETSIDI::setFont("ComicNeue-Regular.ttf", size);
	ETSIDI::printxy(texto, (int)pos.x, (int)pos.y);
}