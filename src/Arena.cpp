
#include "Arena.h"

void Arena::inicializa(Personaje* p1, Personaje* p2)
{
    jugador1 = p1;
    jugador2 = p2;

    jugador1->setPosicion({ 100,300 });
    jugador2->setPosicion({ 700,300 });

    combateTerminado = false;
}

void Arena::mueve(float dt)
{
    jugador1->mueve(dt);
    jugador2->mueve(dt);

    if (!jugador1->estaVivo() ||
        !jugador2->estaVivo())
    {
        combateTerminado = true;
    }
}