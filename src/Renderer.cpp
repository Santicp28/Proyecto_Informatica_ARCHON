#include "Renderer.h"

void Renderer::inicializa2D()
{
	glDisable(GL_DEPTH_TEST);//No hay 3D real de profundidad, todo se dibuja en orden de renderizado
	glDisable(GL_LIGHTING);//Desactiva el sistema de iluminación de OpenGL

	glMatrixMode(GL_PROJECTION);//Cambia al modo matriz de proyección (estás definiendo “cómo se ve la cámara”, no los objetos)
	glLoadIdentity();//Resetea la matriz de proyección
	glOrtho
		(0, Config::sizeMundo.x,// eje x estandar (0= izda, 800= drcha)
		 Config::sizeMundo.y, 0,// eje y invertido (600= abajo, 0= arriba)
		 -1.0, 1.0);//grados de profundidad

	glMatrixMode(GL_MODELVIEW);// todo lo siguiente define como se ven los objetos
}

void Renderer::dibujaCuadrado(const Vector2D& centro, const Color& color, const Vector2D& size)const
{
	Vector2D desplazamiento = size * 0.5;
	dibujaColor(color);
	glBegin(GL_QUADS);

	glVertex3d(centro.x - desplazamiento.x, centro.y - desplazamiento.y, 0.1); // abajo izquierda
	glVertex3d(centro.x + desplazamiento.x, centro.y - desplazamiento.y, 0.1); // abajo derecha
	glVertex3d(centro.x + desplazamiento.x, centro.y + desplazamiento.y, 0.1); // arriba derecha
	glVertex3d(centro.x - desplazamiento.x, centro.y + desplazamiento.y, 0.1); // arriba izquierda

	glEnd();

}

void Renderer::dibujaContornoCuadrado(const Vector2D& centro, const Color& color, const Vector2D& size)const
{
	// 2. Dibujar el borde con un pequeño offset en Z para evitar parpadeo
	Vector2D desplazamiento = size *0.5;
	dibujaColor(color);
	glLineWidth(2.0f);//ancho de lineas
	glBegin(GL_LINE_LOOP);
	glVertex3d(centro.x - desplazamiento.x, centro.y - desplazamiento.y, 0.1); // abajo izquierda
	glVertex3d(centro.x + desplazamiento.x, centro.y - desplazamiento.y, 0.1); // abajo derecha
	glVertex3d(centro.x + desplazamiento.x, centro.y + desplazamiento.y, 0.1); // arriba derecha
	glVertex3d(centro.x - desplazamiento.x, centro.y + desplazamiento.y, 0.1); // arriba izquierda
	glEnd();
}


void Renderer::dibujaOvalo(const Vector2D& centro, const Color& color, double radioX, double radioY) const {
	dibujaColor(color);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 24; i++)
	{
		double a = 2.0f * Config::PI * i / 24.0f;
		glVertex3d(centro.x + cos(a) * radioX,centro.y + sin(a) * radioY,0.1);
	}
	glEnd();
}