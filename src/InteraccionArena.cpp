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

bool InteraccionArena::colision(const Disparo& d, const Bordes& b)
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


void InteraccionArena::colision(Pieza& p, const Obstaculo& obs)
{
    Vector2D diff = p.posicion_ - obs.posicion;
    double dist = diff.modulo();
    double sumRadios = p.sizeradio_ + obs.size.x * 0.5;
    if (dist >= sumRadios) return;

    Vector2D dir = diff.unitario();
    double solape = sumRadios - dist;
    p.posicion_ = p.posicion_ + dir * solape; // solo mueve la pieza, el obstáculo es estático
}

bool InteraccionArena::colision(const Disparo& d, const Obstaculo& obs)
{
    Vector2D diff = d.posicion_ - obs.posicion;
    double dist = diff.modulo();
    double sumRadios = d.sizeradio_ + obs.size.x * 0.5;
    return dist < sumRadios;
}

bool InteraccionArena::colision(const GolpeAtaque& golpe, const Vector2D& posAtacante,
    const Vector2D& dir, const Pieza& defensor)
{
    return golpe.colisiona(posAtacante, dir, defensor.posicion_, defensor.sizeradio_);
}
bool InteraccionArena::colision(const GritoArea& grito, const Vector2D& posBanshee, const Pieza& defensor)
{
    return grito.dentroDelArea(posBanshee, defensor.posicion_);
}
