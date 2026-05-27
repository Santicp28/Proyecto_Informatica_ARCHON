#include "Arena.h"

void Arena::inicializa(Pieza* p1, Pieza* p2)
{
    jugador1 = p1;
    jugador2 = p2;
    jugador1->setPosicionArena(posicionInicialJugador1);
    jugador2->setPosicionArena(posicionInicialJugador2);

    combateTerminado = false;
    ganadorBando = 0;
   
}
void Arena::tecla(unsigned char key) { teclas[key] = true; }
void Arena::teclaUP(unsigned char key) { teclas[key] = false; }
void Arena::teclaEspecial(int key) { teclasEspeciales[key] = true; }
void Arena::teclaEspecialUP(int key) { teclasEspeciales[key] = false; }
void Arena::mueve(float dt)
{
    if (combateTerminado) return;
    jugador1->atacar = teclas[' '];

    Vector2D vel1(0, 0);
    double speed1 = jugador1->getVelocidadMovimiento();
    if (teclas['w'] || teclas['W']) vel1.y = speed1;
    if (teclas['s'] || teclas['S']) vel1.y = -speed1;
    if (teclas['a'] || teclas['A']) vel1.x = -speed1;
    if (teclas['d'] || teclas['D']) vel1.x = speed1;
    if (vel1.modulo() > 0)
        vel1 = vel1.unitario() * speed1;
    jugador1->velocidad(vel1);



    jugador2->atacar = teclasEspeciales[13];
    Vector2D vel2(0, 0);
    double speed2 = jugador2->getVelocidadMovimiento();
    if (teclasEspeciales[GLUT_KEY_UP]) vel2.y = speed2;
    if (teclasEspeciales[GLUT_KEY_DOWN]) vel2.y = -speed2;
    if (teclasEspeciales[GLUT_KEY_LEFT]) vel2.x = -speed2;
    if (teclasEspeciales[GLUT_KEY_RIGHT]) vel2.x = speed2;
    if (vel2.modulo() > 0)
        vel2 = vel2.unitario() * speed2;
    jugador2->velocidad(vel2);

    jugador1->mueve(dt);
    jugador2->mueve(dt);
}

void Arena::dibuja(const Renderer& renderer) const
{
    bordes.dibuja(renderer);
}

Pieza* Arena::getGanador() const
{
    if (!combateTerminado) return nullptr;
    if (ganadorBando == 1) return jugador1;
    if (ganadorBando == 2) return jugador2;
    return nullptr; // empate
}
