
#include "Arena.h"
#include "freeglut.h"

//SIN DEPENDER DE PIEZA

void Arena::inicializa(Pieza* p1, Pieza* p2)
{
    // guardamos los punteros a las piezas del tablero
    jugador1.pieza = p1;
    jugador2.pieza = p2;

    // vida se resetea a su valor por defecto de EstadoCombate
    jugador1.vida = jugador1.vidaMax;
    jugador2.vida = jugador2.vidaMax;

    // posicionamos jugadores: jugador1 izquierda, jugador2 derecha
    jugador1.posicion = { 150.0f, 300.0f };
    jugador2.posicion = { 650.0f, 300.0f };

    // velocidades a cero
    jugador1.velocidad = { 0, 0 };
    jugador2.velocidad = { 0, 0 };

    // cooldowns y flags a cero
    jugador1.cooldown = 0.f;
    jugador2.cooldown = 0.f;

    jugador1.atacar = false;
    jugador2.atacar = false;

    combateTerminado = false;
    ganadorBando = 0;
   
}

void Arena::mueve(float dt)

{

    if (combateTerminado) return;

    if (combateTerminado) return;

    //MOVER
    jugador1.posicion = jugador1.posicion + jugador1.velocidad * dt;
    jugador2.posicion = jugador2.posicion + jugador2.velocidad * dt;

    //COOLDOWNS
    jugador1.cooldown -= dt; if (jugador1.cooldown < 0) jugador1.cooldown = 0;
    jugador2.cooldown -= dt; if (jugador2.cooldown < 0) jugador2.cooldown = 0;

    //COLISIÓN CON BORDES
    InteraccionArena::rebote(jugador1.posicion, jugador1.velocidad, jugador1.radio, bordes);
    InteraccionArena::rebote(jugador2.posicion, jugador2.velocidad, jugador2.radio, bordes);

    //ATAQUES
    if (jugador1.atacar && jugador1.cooldown <= 0)
        procesarAtaque(jugador1, jugador2);

    if (jugador2.atacar && jugador2.cooldown <= 0)
        procesarAtaque(jugador2, jugador1);

    //VICTORIA — comprobamos los dos a la vez para detectar empate
    bool muereJ1 = jugador1.vida <= 0;
    bool muereJ2 = jugador2.vida <= 0;
   
    if (muereJ1 && muereJ2)
    {
        // empate — mueren los dos en el mismo frame
        combateTerminado = true;
        ganadorBando = 0;
    }
    else if (muereJ1)
    {
        combateTerminado = true;
        ganadorBando = 2;
    }
    else if (muereJ2)
    {
        combateTerminado = true;
        ganadorBando = 1;
    }
}
void Arena::procesarAtaque(EstadoCombate& atacante,EstadoCombate& defensor)
{
    if (InteraccionArena::colisionMelee(atacante.posicion, atacante.radio,defensor.posicion, defensor.radio))
    {
        // valores fijos mientras Pieza no tenga getters
        double danioFijo = 10.0;
        float cadenciaFija = 1.0f;

        defensor.vida -= danioFijo;
        if (defensor.vida < 0) defensor.vida = 0;

        atacante.cooldown = cadenciaFija;
        atacante.atacar = false;
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

    dibujarCombatiente(jugador1);
    dibujarCombatiente(jugador2);

    dibujarBarraVida(jugador1.pieza, 50.0f, 30.0f);
    dibujarBarraVida(jugador2.pieza, 550.0f, 30.0f);

    glEnable(GL_LIGHTING);

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

void Arena::dibujarBarraVida(const Pieza* p, float x, float y) const
{
    float ancho = 200.0f;
    float alto = 15.0f;
    // buscamos el EstadoCombate correspondiente a la pieza
    // para leer la vida de EstadoCombate, no de Pieza
    const EstadoCombate& c = (jugador1.pieza == p) ? jugador1 : jugador2;
    float porcentaje = (float)(c.vida / c.vidaMax);

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

void Arena::dibujarCombatiente(const EstadoCombate& c) const
{
    glPushMatrix();
    glTranslatef(c.posicion.x, c.posicion.y, 0);

    if (c.pieza == jugador1.pieza)
        glColor3f(1.0f, 1.0f, 1.0f);
    else
        glColor3f(0.15f, 0.15f, 0.15f);

    glBegin(GL_POLYGON);
    for (int i = 0; i < 32; i++)
    {
        float a = 2.0f * 3.14159f * i / 32;
        glVertex2f(cos(a) * c.radio, sin(a) * c.radio);
    }
    glEnd();

    glPopMatrix();
}

void Arena::tecla(unsigned char key)
{
    if (combateTerminado) return;
    switch (key)
    {
    case 'w': jugador1.velocidad = { 0,  VELOCIDAD }; break;
    case 's': jugador1.velocidad = { 0, -VELOCIDAD }; break;
    case 'a': jugador1.velocidad = { -VELOCIDAD, 0 }; break;
    case 'd': jugador1.velocidad = { VELOCIDAD, 0 }; break;
    case ' ': jugador1.atacar = true; break;
    case 13:  jugador2.atacar = true; break; //tecla enter
    }
}

void Arena::teclaEspecial(int key)
{
    if (combateTerminado) return;
    switch (key)
    {
    case GLUT_KEY_UP:    jugador2.velocidad = { 0,  VELOCIDAD }; break;
    case GLUT_KEY_DOWN:  jugador2.velocidad = { 0, -VELOCIDAD }; break;
    case GLUT_KEY_LEFT:  jugador2.velocidad = { -VELOCIDAD, 0 }; break;
    case GLUT_KEY_RIGHT: jugador2.velocidad = { VELOCIDAD, 0 }; break;
    }
}




//POIENDO DENTRO DE PIEZA getters