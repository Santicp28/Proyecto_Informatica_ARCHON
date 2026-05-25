#include "InteraccionArena.h"
#include <cmath>



void InteraccionArena::colision(Pieza& p, const BordesArena& b)
{
    Vector2D dir;
    double radio = p.sizeradio_;
    double dif;

    // Abajo
    dif = b.suelo.distancia(p.posicion_, &dir) - radio;
    if (dif <= 0)
    {
        Vector2D pos = p.posicion_;
        pos.x -= (dir.x * dif);
        pos.y -= (dir.y * dif);
        p.posicion_ = pos;

        Vector2D vel = p.velocidad_;
        double vn = vel.x * dir.x + vel.y * dir.y;
        if (vn < 0)
        {
            vel.x -= vn * dir.x;
            vel.y -= vn * dir.y;
        }
        p.velocidad_= vel;
    }

    // Arriba
    dif = b.techo.distancia(p.posicion_, &dir) - radio;
    if (dif <= 0)
    {
        Vector2D pos = p.posicion_;
        pos.x -= (dir.x * dif);
        pos.y -= (dir.y * dif);
        p.posicion_ = pos;

        Vector2D vel = p.velocidad_;
        double vn = vel.x * dir.x + vel.y *dir.y;
        if (vn < 0)
        {
            vel.x -= vn * dir.x;
            vel.y -= vn * dir.y;
        }
        p.velocidad_ = vel;
    }

    // Izquierda
    dif = b.izq.distancia(p.posicion_, &dir) - radio;
    if (dif <= 0)
    {
        Vector2D pos = p.posicion_;
        pos.x -= (dir.x * dif);
        pos.y -= (dir.y * dif);
        p.posicion_ = pos;

        Vector2D vel = p.velocidad_;
        double vn = vel.x * dir.x + vel.y * dir.y;
        if (vn < 0)
        {
            vel.x -= vn *dir.x;
            vel.y -= vn * dir.y;
        }
        p.velocidad_ = vel;
    }

    // Derecha
    dif = b.dcha.distancia(p.posicion_, &dir) - radio;
    if (dif <= 0)
    {
        Vector2D pos = p.posicion_;
        pos.x -= (dir.x * dif);
        pos.y -= (dir.y * dif);
        p.posicion_ = pos;

        Vector2D vel = p.velocidad_;
        double vn = vel.x * dir.x + vel.y * dir.y;
        if (vn < 0)
        {
            vel.x -= vn * dir.x;
            vel.y -= vn * dir.y;
        }
        p.velocidad_ = vel;
    }
}

double InteraccionArena::distancia(const Vector2D& a, const Vector2D& b)
{
    double dx = b.x-a.x;
    double dy = b.y-a.y;
    return std::sqrt(dx * dx + dy * dy);
}

bool InteraccionArena::colision(const Pieza& p1, const Pieza& p2)
{
    return distancia(p1.posicion_, p2.posicion_) < (p1.sizeradio_ + p2.sizeradio_);
}

bool InteraccionArena::colision(const Disparo& d, const Pieza& p)
{
    return distancia(d.posicion_, p.posicion_)< (d.sizeradio_ + p.sizeradio_);
}

bool InteraccionArena::colision(Disparo& d, const BordesArena& b)
{
    Vector2D dir;
    double dif;

    // Suelo
    dif = b.suelo.distancia(d.posicion_, &dir)- d.sizeradio_;

    if (dif <= 0)
    {
        d.posicion_ =
        d.posicion_ - dir * dif;

        d.velocidad_ = { 0,0 };
        d.aceleracion_ = { 0,0 };

        return true;
    }

    // Techo
    dif = b.techo.distancia(d.posicion_, &dir)- d.sizeradio_;

    if (dif <= 0)
    {
        d.posicion_ =
            d.posicion_ - dir * dif;

        d.velocidad_ = { 0,0 };
        d.aceleracion_ = { 0,0 };

        return true;
    }

    // Izquierda
    dif = b.izq.distancia(d.posicion_, &dir)- d.sizeradio_;

    if (dif <= 0)
    {
        d.posicion_ =
            d.posicion_ - dir * dif;

        d.velocidad_ = { 0,0 };
        d.aceleracion_ = { 0,0 };

        return true;
    }

    // Derecha
    dif = b.dcha.distancia(d.posicion_, &dir)- d.sizeradio_;

    if (dif <= 0)
    {
        d.posicion_ =
            d.posicion_ - dir * dif;

        d.velocidad_ = { 0,0 };
        d.aceleracion_ = { 0,0 };

        return true;
    }

    return false;
}