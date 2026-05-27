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

void Arena::mueve(float dt)
{
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
void Arena::tecla(unsigned char key)
{
    if (combateTerminado) return;
    Vector2D vel(0,0);
    double speed = 0;
    vel = jugador1->velocidad(); 
    speed = jugador1->getVelocidadMovimiento(); 
    switch (key)
    {
    case 'w': 
    case 'W': 
        vel.y = speed; 
        break;
    case 's': 
    case 'S': 
        vel.y = -speed; 
        break;
    case 'a': 
    case 'A': 
        vel.x = -speed; 
        break;
    case 'd': 
    case 'D': 
        vel.x = speed; 
        break;
    case ' ':  
        jugador1->atacar = true;
        break;
    case 13:   
        jugador2->atacar = true;
        break;
    }
    if (vel.modulo() > 0)
        vel = vel.unitario() * speed;
   jugador1->velocidad(vel);  
}


void Arena::teclaUP(unsigned char key)
{
    Vector2D vel = jugador1->velocidad();

    switch (key)
    {
    case 'w': 
    case 'W':
    case 's': 
    case 'S':
        vel.y = 0;
        break;

    case 'a': 
    case 'A':
    case 'd': 
    case 'D':
        vel.x = 0;
        break;

    case ' ':
        jugador1->atacar = false;
        break;
    }

    jugador1->velocidad(vel);
}


void Arena::teclaEspecial(int key)
{
    if (combateTerminado) return;
    Vector2D vel = jugador2->velocidad();
    double speed = jugador2->getVelocidadMovimiento();
    switch (key)
    {
    case GLUT_KEY_UP:
        vel.y = speed;
        break;

    case GLUT_KEY_DOWN:
        vel.y = -speed;
        break;

    case GLUT_KEY_LEFT:
        vel.x = -speed;
        break;

    case GLUT_KEY_RIGHT:
        vel.x = speed;
        break;
    }
    if (vel.modulo() > 0)
       vel = vel.unitario() * speed;
    jugador2->velocidad(vel);
}
void Arena::teclaEspecialUP(int key)
{
    Vector2D vel = jugador2->velocidad();
    switch (key)
    {

    case GLUT_KEY_UP:
    case GLUT_KEY_DOWN:
        vel.y = 0;
        break;
    case GLUT_KEY_LEFT:
    case GLUT_KEY_RIGHT:
        vel.x = 0;
        break;
    }
    jugador2->velocidad(vel);
}
