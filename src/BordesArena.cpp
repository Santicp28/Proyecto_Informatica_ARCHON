#include "BordesArena.h"
#include "freeglut.h"

void BordesArena::dibuja() const
{
    glDisable(GL_LIGHTING);
    glColor3f(0.15f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex3f(50, 50, 0);
    glVertex3f(750, 50, 0);
    glVertex3f(750, 550, 0);
    glVertex3f(50, 550, 0);
    glEnd();
    glEnable(GL_LIGHTING);

    suelo.dibuja();
    techo.dibuja();
    izq.dibuja();
    dcha.dibuja();
}