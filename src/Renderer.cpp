#include "ETSIDI.h"
#include "freeglut.h"
#include "Renderer.h"
#include "Config.h"
#include <memory>

void Renderer::inicializa2D()
{
	glDisable(GL_DEPTH_TEST);//No hay 3D real de profundidad, todo se dibuja en orden de renderizado
	glDisable(GL_LIGHTING);//Desactiva el sistema de iluminación de OpenGL

	glMatrixMode(GL_PROJECTION);//Cambia al modo matriz de proyección (estás definiendo “cómo se ve la cámara”, no los objetos)
	glLoadIdentity();//Resetea la matriz de proyección
	glOrtho
		(0, Config::sizeMundo.x,// eje x estandar (0= izda, 800= drcha)    útil para menus
		 Config::sizeMundo.y, 0,// eje y invertido (600= abajo, 0= arriba)
		 -1.0, 1.0);//grados de profundidad

	glMatrixMode(GL_MODELVIEW);// todo lo siguiente define como se ven los objetos
}

void Renderer::dibujaCuadrado(const Vector2D& centro, const Color& color, const Vector2D& size)const
{
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	Vector2D desplazamiento = size * 0.5;
	dibujaColor(color);
	glBegin(GL_QUADS);

	glVertex2d(centro.x - desplazamiento.x, centro.y - desplazamiento.y); // arriba izquierda
	glVertex2d(centro.x + desplazamiento.x, centro.y - desplazamiento.y); // arriba derecha
	glVertex2d(centro.x + desplazamiento.x, centro.y + desplazamiento.y); // abajo derecha
	glVertex2d(centro.x - desplazamiento.x, centro.y + desplazamiento.y); // abajo izquierda

	glEnd();
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}

void Renderer::dibujaContornoCuadrado(const Vector2D& centro, const Color& color, const Vector2D& size)const
{
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	// 2. Dibujar el borde con un pequeño offset en Z para evitar parpadeo
	Vector2D desplazamiento = size *0.5;
	dibujaColor(color);
	glLineWidth(2.0f);//ancho de lineas
	glBegin(GL_LINE_LOOP);
	glVertex2d(centro.x - desplazamiento.x, centro.y - desplazamiento.y); // abajo izquierda
	glVertex2d(centro.x + desplazamiento.x, centro.y - desplazamiento.y); // abajo derecha
	glVertex2d(centro.x + desplazamiento.x, centro.y + desplazamiento.y); // arriba derecha
	glVertex2d(centro.x - desplazamiento.x, centro.y + desplazamiento.y); // arriba izquierda
	glEnd();
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}



void Renderer::dibujaLinea(const Vector2D& limite1, const Vector2D& limite2, const Color& color) const
{
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	dibujaColor(color);
	glLineWidth(2.0f);//ancho de lineas
	glBegin(GL_LINES);
	glVertex2d(limite1.x, limite1.y);
	glVertex2d(limite2.x, limite2.y);
	glEnd();
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}

void Renderer::dibujaOvalo(const Vector2D& centro, const Color& color, double radioX, double radioY) const {
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	dibujaColor(color);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 24; i++)
	{
		double a = 2.0f * Config::PI * i / 24.0f;
		glVertex3d(centro.x + cos(a) * radioX,centro.y + sin(a) * radioY,0.1);
	}
	glEnd();
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}
void Renderer::cuadradoParaPruebas() const
{
	dibujaCuadrado(Config::sizeMundo * 0.5, { 1.0,1.0,1.0 }, Config::sizeMundo * 0.2);
}
void Renderer::dibujaSprite(const char* rutaPNG, const Vector2D& centro, double ancho, double alto) const {
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	ETSIDI::Sprite sprite(rutaPNG, (double)(centro.x), (double)(centro.y), (double)ancho, (double)alto);
	sprite.flip(false, true);
	sprite.draw();
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}

void Renderer::dibujaSprite(const ETSIDI::Sprite& sprite, const Vector2D& centro, double ancho, double alto) const {
	ETSIDI::Sprite s = sprite; // copia el sprite ya cargado
	s.setPos(centro.x - (ancho / 2.0), centro.y + (alto / 2.0));
	s.setSize(ancho, alto);
	s.flip(false, true);
	s.draw();
	glDisable(GL_LIGHTING);
}

void Renderer::dibujaTexto(const char* texto, const Vector2D& pos, double r, double g, double b, int size) const {
	ETSIDI::setTextColor(r, g, b);
	ETSIDI::setFont("ComicNeue-Regular.ttf", size);
	ETSIDI::printxy(texto, (int)pos.x, (int)pos.y);
void Renderer::dibujaTexto(const std::string& texto, const Vector2D& pos, const Color& color, int size) const {
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
	const char* p = texto.c_str();//convierte el string a un puntero a char para que lo acepte la función printxy
	float correccionAncho = (texto.size()-1.0) * size * 0.5f;//el -1 es porque el \0 descentra el texo
	float correccionAlto = size * 0.5f;//corrección para que el texto quede centrado porque printxy dibuja el texto a partir de la esquina superior izquierda

	ETSIDI::setTextColor(color.r, color.g, color.b);
	ETSIDI::setFont("assets/fuentes/ComicNeue-Regular.ttf", size);
	ETSIDI::printxy(p, (int)(pos.x - correccionAncho), (int)(pos.y + correccionAlto));//conversion tipo cast
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}

