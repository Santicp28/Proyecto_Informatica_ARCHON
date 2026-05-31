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

void Renderer::dibujaCuadrado(const unique_ptr<Sprite>& sprite, const Vector2D& centro, const Color& color, const Vector2D& size)const
{
	empiezaUI();
	if (sprite)
		dibujaSprite(sprite, centro, size); 
	else
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
		
	terminaUI();
}

void Renderer::dibujaContornoCuadrado(const unique_ptr<Sprite>& sprite, const Vector2D& centro, const Color& color, const Vector2D& size)const
{
	empiezaUI();
	if (sprite)
		dibujaSprite(sprite, centro, size); 
	else
	{
		Vector2D desplazamiento = size * 0.5;
		dibujaColor(color);
		glLineWidth(2.0f);//ancho de lineas
		glBegin(GL_LINE_LOOP);
		glVertex2d(centro.x - desplazamiento.x, centro.y - desplazamiento.y); // abajo izquierda
		glVertex2d(centro.x + desplazamiento.x, centro.y - desplazamiento.y); // abajo derecha
		glVertex2d(centro.x + desplazamiento.x, centro.y + desplazamiento.y); // arriba derecha
		glVertex2d(centro.x - desplazamiento.x, centro.y + desplazamiento.y); // arriba izquierda
		glEnd();
	}	
	terminaUI();
}

void Renderer::dibujaLinea(const Vector2D& limite1, const Vector2D& limite2, const Color& color) const
{
	empiezaUI();
	dibujaColor(color);
	glLineWidth(2.0f);//ancho de lineas
	glBegin(GL_LINES);
	glVertex2d(limite1.x, limite1.y);
	glVertex2d(limite2.x, limite2.y);
	glEnd();
	terminaUI();
}

void Renderer::dibujaOvalo(const unique_ptr<Sprite>& sprite,const Vector2D& centro, const Color& color, double radioX, double radioY) const {
	empiezaUI();
	if (sprite)
		dibujaSprite(sprite, centro, {radioX, radioY});
	else 
	{
		dibujaColor(color);
		glBegin(GL_POLYGON);
		for (int i = 0; i < 24; i++)
		{
			double a = 2.0f * Config::PI * i / 24.0f;
			glVertex3d(centro.x + cos(a) * radioX, centro.y + sin(a) * radioY, 0.1);
		}
		glEnd();
	}
	terminaUI();
}

void Renderer::dibujaSprite(const unique_ptr<Sprite>& sprite, const Vector2D& centro, const Vector2D& size) const {
	empiezaUI();
	sprite->setPos(centro.x - (size.x / 2.0), centro.y + (size.y / 2.0));
	sprite->setSize(size.x, size.y);
	sprite->flip(false, true);
	sprite->draw();
	terminaUI();
}

void Renderer::dibujaTexto(const std::string& texto, const Vector2D& pos, const Color& color, int size, AlineacionTexto alineacion) const {
	empiezaUI();
	const char* p = texto.c_str();//convierte el string a un puntero a char para que lo acepte la función printxy

	float correccionAlto = size * 0.5f;//corrección para que el texto quede centrado porque printxy dibuja el texto a partir de la esquina superior izquierda

	if (alineacion == AlineacionTexto::IZQUIERDA) {
		ETSIDI::setTextColor(color.r, color.g, color.b);
		ETSIDI::setFont("assets/fuentes/ComicNeue-Regular.ttf", size);
		ETSIDI::printxy(p, (int)(pos.x), (int)(pos.y + correccionAlto));//conversion tipo cast
	}  
	else if (alineacion == AlineacionTexto::CENTRADO) {
		float correccionAncho = (texto.size() - 1.0) * size * 0.5f;//el -1 es porque el \0 descentra el texo

		ETSIDI::setTextColor(color.r, color.g, color.b);
		ETSIDI::setFont("assets/fuentes/ComicNeue-Regular.ttf", size);
		ETSIDI::printxy(p, (int)(pos.x - correccionAncho), (int)(pos.y + correccionAlto));
	}
	terminaUI();
}

void Renderer::empiezaUI() const {
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);
}
void Renderer::terminaUI() const {
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}

void Renderer::dibujaSpriteRotado(const char* rutaPNG, const Vector2D& base, double ancho, double alto, double angulo) const
{
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glTranslatef(base.x, base.y, 0.0f);
	glRotatef(angulo, 0.0f, 0.0f, 1.0f);

	// dibuja con la base anclada en el origen, la punta hacia arriba
	ETSIDI::Sprite sprite(rutaPNG, -ancho / 2.0 + 20.0, -alto / 2.0, ancho, alto);
	sprite.flip(false, true);
	sprite.draw();

	glPopMatrix();

	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
}