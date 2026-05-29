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
        printf("dif: %f\n", dif);
        if (dif <= 0) return true;
    }
    return false;
}

bool InteraccionArena::colision(const Disparo& d, const Pieza& p)
{
	double dist = (d.posicion_- p.posicion_).modulo();
	return dist < (d.sizeradio_ + p.sizeradio_);
}


//double InteraccionArena::distancia(const Vector2D& a, const Vector2D& b)
//{
//    double dx = b.x-a.x;
//    double dy = b.y-a.y;
//    return std::sqrt(dx * dx + dy * dy);
//}
//
void InteraccionArena::resolverColision(ObjetoMovil& obj1, ObjetoMovil& obj2)
{
    Vector2D diff = obj1.posicion_ - obj2.posicion_;
    double dist = diff.modulo();
    double sumRadios = obj1.sizeradio_ + obj2.sizeradio_;
    if (dist >= sumRadios) return;

    Vector2D dir = diff.unitario();
    double solape = sumRadios - dist;
    obj1.posicion_ = obj1.posicion_ + dir * (solape * 0.5);
    obj2.posicion_ = obj2.posicion_ - dir * (solape * 0.5);
}

void InteraccionArena::colision(Pieza& p1, Pieza& p2)
{
    resolverColision(p1, p2);
}

