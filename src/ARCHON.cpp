#include "Juego.h"
#include"Renderer.h"
#include "freeglut.h"
#include <vector>

Juego juego;
Renderer renderer;

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnSpecialKeyboardDown(int key, int x, int y);

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

    // CALLBACKS
    glutDisplayFunc(OnDraw);
    glutTimerFunc(25, OnTimer, 0);
    glutKeyboardFunc(OnKeyboardDown);
    glutSpecialFunc(OnSpecialKeyboardDown);

    glutMainLoop();
    return 0;
}

// --------------------------------------------------

void OnDraw(void)
{   
    renderer.iniciaFrame();

    juego.dibuja(renderer);

    glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x, int y)
{
    juego.tecla(key);
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