#include "InteraccionArena.h"
#include <cmath>


void InteraccionArena::resolverBorde(ObjetoMovil& obj, const Pared& pared) {
    Vector2D dir;
    double dif = pared.distancia(obj.posicion_, &dir) - obj.sizeradio_;
    if (dif > 0) return;

    obj.posicion_ = obj.posicion_-dir * dif;

    double vn = obj.velocidad_*(dir);
    if (vn < 0)
        obj.velocidad_ = obj.velocidad_- dir * vn;
}
void InteraccionArena::colision(Pieza& p, const Bordes& b)
{
    resolverBorde(p, b.suelo);
    resolverBorde(p, b.techo);
    resolverBorde(p, b.izq);
    resolverBorde(p, b.dcha);
}



bool InteraccionArena::colision(Disparo& d, const Bordes& b)
{
    const Pared* paredes[] = { &b.suelo, &b.techo, &b.izq, &b.dcha };
    for (const Pared* pared : paredes) {
        Vector2D dir;
        double dif = pared->distancia(d.posicion_, &dir) - d.sizeradio_;
        if (dif <= 0) return true;
    }
    return false;
}


//double InteraccionArena::distancia(const Vector2D& a, const Vector2D& b)
//{
//    double dx = b.x-a.x;
//    double dy = b.y-a.y;
//    return std::sqrt(dx * dx + dy * dy);
//}
//
//bool InteraccionArena::colision(const Pieza& p1, const Pieza& p2)
//{
//    return distancia(p1.posicion_, p2.posicion_) < (p1.sizeradio_ + p2.sizeradio_);
//}
//
//bool InteraccionArena::colision(const Disparo& d, const Pieza& p)
//{
//    return distancia(d.posicion_, p.posicion_)< (d.sizeradio_ + p.sizeradio_);
//}
//