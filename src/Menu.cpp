#include "Menu.h"
#include "freeglut.h"

void Menu::inicializa(int anchoVentana, int altoVentana)
{
    botones.clear();

    float bw = 240.0f;
    float bh = 60.0f;
    float x = anchoVentana / 2.0f - bw / 2.0f;

    botones.push_back({ x, 340.0f, bw, bh, "JUGAR", false });
    botones.push_back({ x, 250.0f, bw, bh, "RANKING", false });
    botones.push_back({ x, 160.0f, bw, bh, "SALIR", false });

    quiere_jugar = false;
    quiere_salir = false;
    quiere_ranking = false;
}

void Menu::dibuja()
{
    glClearColor(0.08f, 0.08f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glColor3f(1.0f, 0.9f, 0.3f);
    dibujarTexto(340.0f, 520.0f, "ARCHON");

    glColor3f(0.85f, 0.85f, 0.85f);
    dibujarTexto(260.0f, 480.0f, "Pulsa el raton o usa teclado");

    for (const auto& b : botones) {
        if (b.hover)
            glColor3f(0.3f, 0.5f, 0.9f);
        else
            glColor3f(0.2f, 0.25f, 0.4f);

        glBegin(GL_QUADS);
        glVertex2f(b.x, b.y);
        glVertex2f(b.x + b.w, b.y);
        glVertex2f(b.x + b.w, b.y + b.h);
        glVertex2f(b.x, b.y + b.h);
        glEnd();

        glColor3f(1, 1, 1);
        glBegin(GL_LINE_LOOP);
        glVertex2f(b.x, b.y);
        glVertex2f(b.x + b.w, b.y);
        glVertex2f(b.x + b.w, b.y + b.h);
        glVertex2f(b.x, b.y + b.h);
        glEnd();

        dibujarTexto(b.x + 75.0f, b.y + 25.0f, b.texto);
    }

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void Menu::mueve(float dt)
{
}

void Menu::tecla(unsigned char key)
{
    if (key == 'j' || key == 'J')
        quiere_jugar = true;

    if (key == 'r' || key == 'R')
        quiere_ranking = true;

    if (key == 27)
        quiere_salir = true;
}

void Menu::teclaEspecial(int key)
{
}

void Menu::raton(int button, int state, int x, int y, int altoVentana)
{
    if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN)
        return;

    for (const auto& b : botones) {
        if (estaDentro(b, x, y, altoVentana)) {
            if (b.texto == "JUGAR") quiere_jugar = true;
            if (b.texto == "RANKING") quiere_ranking = true;
            if (b.texto == "SALIR") quiere_salir = true;
        }
    }
}

void Menu::movimientoRaton(int x, int y, int altoVentana)
{
    for (auto& b : botones) {
        b.hover = estaDentro(b, x, y, altoVentana);
    }
}

bool Menu::getQuiereJugar() const
{
    return quiere_jugar;
}

bool Menu::getQuiereSalir() const
{
    return quiere_salir;
}

bool Menu::getQuiereRanking() const
{
    return quiere_ranking;
}

void Menu::resetAcciones()
{
    quiere_jugar = false;
    quiere_salir = false;
    quiere_ranking = false;
}

bool Menu::estaDentro(const Boton& b, int x, int y, int altoVentana) const
{
    int yOpenGL = altoVentana - y;

    return x >= b.x && x <= b.x + b.w &&
        yOpenGL >= b.y && yOpenGL <= b.y + b.h;
}

void Menu::dibujarTexto(float x, float y, const std::string& texto) const
{
    glRasterPos2f(x, y);
    for (char c : texto) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}