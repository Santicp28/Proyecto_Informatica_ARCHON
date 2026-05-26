#include "Renderer.h"
#include "Config.h"

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
	Vector2D desplazamiento = size * 0.5;
	dibujaColor(color);
	glBegin(GL_QUADS);

	glVertex2d(centro.x - desplazamiento.x, centro.y - desplazamiento.y); // arriba izquierda
	glVertex2d(centro.x + desplazamiento.x, centro.y - desplazamiento.y); // arriba derecha
	glVertex2d(centro.x + desplazamiento.x, centro.y + desplazamiento.y); // abajo derecha
	glVertex2d(centro.x - desplazamiento.x, centro.y + desplazamiento.y); // abajo izquierda

	glEnd();

}

void Renderer::dibujaContornoCuadrado(const Vector2D& centro, const Color& color, const Vector2D& size)const
{
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
}

void Renderer::dibujaLinea(const Vector2D& limite1, const Vector2D& limite2, const Color& color) const
{
	dibujaColor(color);
	glLineWidth(2.0f);//ancho de lineas
	glBegin(GL_LINES);
	glVertex2d(limite1.x, limite1.y);
	glVertex2d(limite2.x, limite2.y);
	glEnd();
}

void Renderer::cuadradoParaPruebas() const
{
	dibujaCuadrado(Config::sizeMundo * 0.5, { 1.0,1.0,1.0 }, Config::sizeMundo * 0.2);
}
