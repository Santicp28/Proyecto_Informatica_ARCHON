#include "freeglut.h"
#include "Tablero.h"
#include "TiposPiezas.h"
#include <vector>

// Objeto global de tablero
std::vector<Piezas*> misPiezas;
VisualBoard tablero(1.2f);// cellSize un poco más grande
float offset = -(9 * 1.2f) / 2.0f;
 

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Cámara posicionada para ver el tablero de frente
    gluLookAt(0.0, 0.0, 15.0,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0);

    tablero.draw();

    for (auto p : misPiezas) {
        p->dibujar();
    }

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Archon Project - Board Ready");

    // Configuración inicial de OpenGL
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    misPiezas.push_back(new PiezaEsferica(0, 4, true, offset, 1.2f));  // Líder Luz
    misPiezas.push_back(new PiezaCubica(8, 4, false, offset, 1.2f));  // Líder Oscuridad

    // Callbacks
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(display);

    glutMainLoop();
    return 0;
}