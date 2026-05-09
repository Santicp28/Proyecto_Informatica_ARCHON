#include "freeglut.h"
#include "Pared.h"

void Pared::dibuja() const
{
    glDisable(GL_LIGHTING);
    glColor3ub(color_.r, color_.g, color_.b);
    glBegin(GL_POLYGON);
    glVertex3d(limite1_.x, limite1_.y, 10);
    glVertex3d(limite2_.x, limite2_.y, 10);
    glVertex3d(limite2_.x, limite2_.y, -10);
    glVertex3d(limite1_.x, limite1_.y, -10);
    glEnd();
    glEnable(GL_LIGHTING);
}

Pared::Pared(const Vector2D& l1, const Vector2D& l2, const Color& c)
{
    limite1_ = l1;
    limite2_ = l2;
    color_ = c;
}

double Pared::distancia(const Vector2D& p, Vector2D* pdir) const
{
    Vector2D u = (p - limite1_), dir,
        v = (limite2_ - limite1_).unitario();
    if (auto valor = u * v; valor < 0)
        dir = u;
    else if (valor > (limite1_ - limite2_).modulo())
        dir = (p - limite2_);
    else dir = u - v * valor;

    if (pdir != 0) *pdir = dir.unitario();
    return dir.modulo();
}