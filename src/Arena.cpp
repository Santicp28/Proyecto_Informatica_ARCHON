
#include "Arena.h"
#include "freeglut.h"

//SIN DEPENDER DE PIEZA
//Resetea el estado completo del combate
void Arena::inicializa(Pieza* p1, Pieza* p2)
{
    // guardamos los punteros a las piezas del tablero
    jugador1-> setPosicion;
    jugador2 = p2;

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

//Actualiza físicas, ataques y condición de victoria cada frame
void Arena::mueve(float dt)

{

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

    ////ATAQUES
    //if (jugador1.atacar && jugador1.cooldown <= 0)procesarAtaque(jugador1, jugador2, dt);

    //if (jugador2.atacar && jugador2.cooldown <= 0) procesarAtaque(jugador2, jugador1, dt);

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
void Arena::dibuja() const
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, BordesArena::SizeArena.x, 0, BordesArena::SizeArena.y);

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

// Gestiona input de teclado: WASD mueve jugador1, espacio ataca
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




