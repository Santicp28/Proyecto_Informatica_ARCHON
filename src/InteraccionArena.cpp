#include "InteraccionArena.h"
#include <cmath>

void InteraccionArena::rebote(Personaje& p, const BordesArena& b)
{
    Vector2D dir;
    float radio = p.getRadio();
    double dif;

    // Suelo
    dif = b.suelo.distancia(p.posicion(), &dir) - radio;
    if (dif <= 0)
    {
        Vector2D pos = p.posicion();
        pos.x -= (float)(dir.x * dif);
        pos.y -= (float)(dir.y * dif);
        p.posicion(pos);

        Vector2D vel = p.velocidad();
        float vn = vel.x * (float)dir.x + vel.y * (float)dir.y;
        if (vn < 0)
        {
            vel.x -= vn * (float)dir.x;
            vel.y -= vn * (float)dir.y;
        }
        p.velocidad(vel);
    }

    // Techo
    dif = b.techo.distancia(p.posicion(), &dir) - radio;
    if (dif <= 0)
    {
        Vector2D pos = p.posicion();
        pos.x -= (float)(dir.x * dif);
        pos.y -= (float)(dir.y * dif);
        p.posicion(pos);

        Vector2D vel = p.velocidad();
        float vn = vel.x * (float)dir.x + vel.y * (float)dir.y;
        if (vn < 0)
        {
            vel.x -= vn * (float)dir.x;
            vel.y -= vn * (float)dir.y;
        }
        p.velocidad(vel);
    }

    // Izquierda
    dif = b.izq.distancia(p.posicion(), &dir) - radio;
    if (dif <= 0)
    {
        Vector2D pos = p.posicion();
        pos.x -= (float)(dir.x * dif);
        pos.y -= (float)(dir.y * dif);
        p.posicion(pos);

        Vector2D vel = p.velocidad();
        float vn = vel.x * (float)dir.x + vel.y * (float)dir.y;
        if (vn < 0)
        {
            vel.x -= vn * (float)dir.x;
            vel.y -= vn * (float)dir.y;
        }
        p.velocidad(vel);
    }

    // Derecha
    dif = b.dcha.distancia(p.posicion(), &dir) - radio;
    if (dif <= 0)
    {
        Vector2D pos = p.posicion();
        pos.x -= (float)(dir.x * dif);
        pos.y -= (float)(dir.y * dif);
        p.posicion(pos);

        Vector2D vel = p.velocidad();
        float vn = vel.x * (float)dir.x + vel.y * (float)dir.y;
        if (vn < 0)
        {
            vel.x -= vn * (float)dir.x;
            vel.y -= vn * (float)dir.y;
        }
        p.velocidad(vel);
    }
}
bool InteraccionArena::colisionMelee(const Personaje& p1, const Personaje& p2)
{
    return distancia(p1, p2) < (p1.getRadio() + p2.getRadio());
}

float InteraccionArena::distancia(const Personaje& p1, const Personaje& p2)
{
    float dx = p2.posicion().x - p1.posicion().x;
    float dy = p2.posicion().y - p1.posicion().y;
    return std::sqrt(dx * dx + dy * dy);
}