
#include "Arena.h"
#include "InteraccionArena.h"
#include "freeglut.h"

void Arena::inicializa(Personaje* p1, Personaje* p2)
{
    jugador1 = p1;
    jugador2 = p2;

    jugador1->posicion({ 150.0f, 300.0f });
    jugador2->posicion({ 650.0f, 300.0f });

    jugador1->velocidad({ 0, 0 });
    jugador2->velocidad({ 0, 0 });

    combateTerminado = false;
    ganadorBando = 0;
}

void Arena::mueve(float dt)

{

    if (combateTerminado) return;

    jugador1->mueve(dt);
    jugador2->mueve(dt);

    InteraccionArena::rebote(*jugador1, bordes);
    InteraccionArena::rebote(*jugador2, bordes);

    if (InteraccionArena::colisionMelee(*jugador1, *jugador2))
    {
        jugador1->atacar();
        jugador2->atacar();
    }

    if (!jugador1->estaVivo())
    {
        combateTerminado = true;
        ganadorBando = 2;
    }
    else if (!jugador2->estaVivo())
    {
        combateTerminado = true;
        ganadorBando = 1;
    }
}

void Arena::dibuja() const
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glDisable(GL_LIGHTING);

    bordes.dibuja();

    jugador1->dibuja();
    jugador2->dibuja();

    dibujarBarraVida(jugador1, 50.0f, 30.0f);
    dibujarBarraVida(jugador2, 550.0f, 30.0f);

    glEnable(GL_LIGHTING);

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void Arena::dibujarBarraVida(const Personaje* p, float x, float y) const
{
    float ancho = 200.0f;
    float alto = 15.0f;
    float porcentaje = (float)p->getVida() / (float)p->getVidaMax();

    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + ancho, y);
    glVertex2f(x + ancho, y + alto);
    glVertex2f(x, y + alto);
    glEnd();

    if (porcentaje > 0.5f)  glColor3f(0.2f, 0.8f, 0.2f);
    else if (porcentaje > 0.25f) glColor3f(0.9f, 0.7f, 0.1f);
    else                         glColor3f(0.9f, 0.1f, 0.1f);

    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + ancho * porcentaje, y);
    glVertex2f(x + ancho * porcentaje, y + alto);
    glVertex2f(x, y + alto);
    glEnd();
}

void Arena::tecla(unsigned char key)
{
    if (!jugador1 || combateTerminado) return;

    if (key == 'w' || key == 'W') jugador1->velocidad({ 0,  180.0f });
    if (key == 's' || key == 'S') jugador1->velocidad({ 0, -180.0f });
    if (key == 'a' || key == 'A') jugador1->velocidad({ -180.0f, 0 });
    if (key == 'd' || key == 'D') jugador1->velocidad({ 180.0f, 0 });
}

void Arena::teclaEspecial(unsigned char key)
{
    if (!jugador2 || combateTerminado) return;

    if (key == GLUT_KEY_UP)    jugador2->velocidad({ 0,  180.0f });
    if (key == GLUT_KEY_DOWN)  jugador2->velocidad({ 0, -180.0f });
    if (key == GLUT_KEY_LEFT)  jugador2->velocidad({ -180.0f, 0 });
    if (key == GLUT_KEY_RIGHT) jugador2->velocidad({ 180.0f, 0 });
}