#include "Juego.h"
#include"Renderer.h"
#include "ContenedorSprites.h"
#include "freeglut.h"
#include <vector>

Juego juego;
Renderer renderer;
ContenedorSprites contenedorSprites{false};

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnSpecialKeyboardDown(int key, int x, int y);
void OnKeyboardUp(unsigned char key, int x, int y);
void OnSpecialKeyboardUp(int key, int x, int y);
void OnResize(int nuevoAncho, int nuevoAlto);
void OnReshape(int ancho, int alto);

int main(int argc, char* argv[])
{
    unsigned int sizePantallaX{ 800 };
    unsigned int sizePantallaY{ 600 };
    glutInit(&argc, argv);
    glutInitWindowSize(sizePantallaX, sizePantallaY);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
    glutCreateWindow("ARCHON");

    renderer.inicializa2D();
    juego.inicializa();
	if(contenedorSprites.modoCargado())
	{
		contenedorSprites.cargarContenedorSprites();
	}

    // CALLBACKS
    glutDisplayFunc(OnDraw);
    glutTimerFunc(25, OnTimer, 0);
    glutKeyboardFunc(OnKeyboardDown);
    glutSpecialFunc(OnSpecialKeyboardDown);
	glutKeyboardUpFunc(OnKeyboardUp);
    glutSpecialUpFunc(OnSpecialKeyboardUp);
    glutReshapeFunc(OnResize);
    glutReshapeFunc(OnReshape);
    glutMainLoop();
    return 0;
}

// --------------------------------------------------

void OnDraw(void)
{   
    renderer.iniciaFrame();

    juego.dibuja(renderer, contenedorSprites);

    glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x, int y)
{
    juego.tecla(key, contenedorSprites);
    glutPostRedisplay();
}

void OnSpecialKeyboardDown(int key, int x, int y)
{
    juego.teclaEspecial(key);
    glutPostRedisplay();
}

void OnTimer(int value)
{
    juego.mueve(0.025f);

    glutTimerFunc(25, OnTimer, 0);
    glutPostRedisplay();
}

void OnKeyboardUp(unsigned char key, int x, int y)
{
	juego.teclaUP(key);
	glutPostRedisplay();
}

void OnSpecialKeyboardUp(int key, int x, int y)
{
	juego.teclaEspecialUP(key);
	glutPostRedisplay();
}

void OnResize(int nuevoAncho, int nuevoAlto)
{
    Config::anchoVentana = nuevoAncho;
    Config::altoVentana = nuevoAlto;
    glViewport(0, 0, nuevoAncho, nuevoAlto);
}

void OnReshape(int ancho, int alto)
{
    const float relacionAspecto = (float)Config::sizeMundo.x / (float)Config::sizeMundo.y;
    float relacionActual = (float)ancho / (float)alto;

    int nuevoAncho = ancho, nuevoAlto = alto;

    if (relacionActual > relacionAspecto)
        nuevoAncho = (int)(alto * relacionAspecto);
    else if (relacionActual < relacionAspecto)
        nuevoAlto = (int)(ancho / relacionAspecto);

    if (nuevoAncho != ancho || nuevoAlto != alto) {
        glutReshapeWindow(nuevoAncho, nuevoAlto);
        return;
    }

    glViewport(0, 0, nuevoAncho, nuevoAlto);
}