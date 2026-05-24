#include "BordesArena.h"
#include "freeglut.h"

void BordesArena::dibuja() const
{
    glDisable(GL_LIGHTING);
    glColor3f(0.15f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(X_MIN, Y_MIN); // esquina inferior izquierda
    glVertex2f(X_MAX, Y_MIN); // esquina inferior derecha
    glVertex2f(X_MAX, Y_MAX); // esquina superior derecha
    glVertex2f(X_MIN, Y_MAX); // esquina superior izquierda
    glEnd();
    glEnable(GL_LIGHTING);

    suelo.dibuja();
    techo.dibuja();
    izq.dibuja();
    dcha.dibuja();
}