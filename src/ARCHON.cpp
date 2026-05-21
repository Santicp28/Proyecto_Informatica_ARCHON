#include "Juego.h"
#include "freeglut.h"
#include <vector>

Juego juego;

void OnDraw(void);
void OnTimer(int value);
void OnKeyboardDown(unsigned char key, int x, int y);
void OnSpecialKeyboardDown(int key, int x, int y);
void OnMouse(int button, int state, int x, int y);
void OnPassiveMotion(int x, int y);

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB );
    glutCreateWindow("ARCHON");

    // OpenGL básico
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Proyección 2D ortográfica
    glOrtho(
        0.0, 800.0,   // eje x estandar
        600.0, 0.0,   // eje y invertido 
        -1.0, 1.0 //grados de profundidad
    );

    // CALLBACKS
    glutDisplayFunc(OnDraw);
    glutTimerFunc(25, OnTimer, 0);
    glutKeyboardFunc(OnKeyboardDown);
    glutSpecialFunc(OnSpecialKeyboardDown);
    glutMouseFunc(OnMouse);
    glutPassiveMotionFunc(OnPassiveMotion);

    juego.inicializa();

    glutMainLoop();
    return 0;
}

// --------------------------------------------------

void OnDraw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    juego.dibuja();

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

void OnMouse(int button, int state, int x, int y)
{
    juego.raton(button, state, x, y);
    glutPostRedisplay();
}

void OnPassiveMotion(int x, int y)
{
    juego.movimientoRaton(x, y);
    glutPostRedisplay();
}

void OnTimer(int value)
{
    juego.mueve(0.025f);

    glutTimerFunc(25, OnTimer, 0);
    glutPostRedisplay();
}