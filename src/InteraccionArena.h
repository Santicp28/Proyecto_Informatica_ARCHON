#pragma once
#include "Personaje.h"
#include "BordesArena.h"

class InteraccionArena
{
public:
    static void rebote(Personaje& p, const BordesArena& b);
    static bool colisionMelee(const Personaje& p1, const Personaje& p2);
    static float distancia(const Personaje& p1, const Personaje& p2);
};