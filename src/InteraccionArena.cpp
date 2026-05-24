#include "InteraccionArena.h"
#include <cmath>
//SIN FISICA EN PIEZA 

void InteraccionArena::rebote(Vector2D& pos,Vector2D& vel, float radio, const BordesArena& bordes)
{

    // ABAJO
    // El radio lo usamos como distancia propia del personaje
    // pos.y - radio = borde inferior del círculo si supera Y_MIN
    //significa que ha tocado la parte de abajo del límite de Arena
        if (pos.y - radio < BordesArena::Y_MIN)
    {
        // empujamos el círculo fuera de la pared
        pos.y = BordesArena::Y_MIN + radio;

        // cancelamos velocidad solo si iba hacia la pared
        // vel.y negativa = va hacia abajo
        if (vel.y < 0) vel.y = 0;
    }
    // ARRIBA
    // pos.y + radio = borde superior del círculo
        if (pos.y + radio > BordesArena::Y_MAX)
        {
            pos.y = BordesArena::Y_MAX - radio;

            // vel.y positiva = va hacia arriba
            if (vel.y > 0) vel.y = 0;
        }

     // PARED IZQUIERDA
     // pos.x - radio = borde izquierdo del círculo
        if (pos.x - radio < BordesArena::X_MIN)
        {
            pos.x = BordesArena::X_MIN + radio;

            // vel.x negativa = va hacia la izquierda
            if (vel.x < 0) vel.x = 0;
        }

        // PARED DERECHA
        // pos.x + radio = borde derecho del círculo
        if (pos.x + radio > BordesArena::X_MAX)
        {
            pos.x = BordesArena::X_MAX - radio;

            // vel.x positiva = va hacia la derecha
            if (vel.x > 0) vel.x = 0;
        }
}


float InteraccionArena::distancia(const Vector2D& pos1, const Vector2D& pos2)
{
    // Teorema de Pitágoras: sqrt( (x2-x1)^2 + (y2-y1)^2 )
    float dx = pos2.x - pos1.x;
    float dy = pos2.y - pos1.y;
    return std::sqrt(dx * dx + dy * dy);
}

bool InteraccionArena::colisionMelee(const Vector2D& pos1, float radio1,const Vector2D& pos2, float radio2)
{
    // Hay contacto cuando la distancia entre centros
    // es menor que la suma de los dos radios
    return distancia(pos1, pos2) < (radio1 + radio2);
}




// CON FISICA EN PIEZA
//void InteraccionArena::rebote(Pieza& p, const BordesArena& b)
//{
//    Vector2D dir;
//    float radio = p.getRadio();
//    double dif;
//
//    // Abajo
//    dif = b.suelo.distancia(p.getPosicion(), &dir) - radio;
//    if (dif <= 0)
//    {
//        Vector2D pos = p.getPosicion();
//        pos.x -= (float)(dir.x * dif);
//        pos.y -= (float)(dir.y * dif);
//        p.setPosicion(pos);
//
//        Vector2D vel = p.getVelocidad();
//        float vn = vel.x * (float)dir.x + vel.y * (float)dir.y;
//        if (vn < 0)
//        {
//            vel.x -= vn * (float)dir.x;
//            vel.y -= vn * (float)dir.y;
//        }
//        p.setVelocidad(vel);
//    }
//
//    // Arriba
//    dif = b.techo.distancia(p.getPosicion(), &dir) - radio;
//    if (dif <= 0)
//    {
//        Vector2D pos = p.getPosicion();
//        pos.x -= (float)(dir.x * dif);
//        pos.y -= (float)(dir.y * dif);
//        p.setPosicion(pos);
//
//        Vector2D vel = p.getVelocidad();
//        float vn = vel.x * (float)dir.x + vel.y * (float)dir.y;
//        if (vn < 0)
//        {
//            vel.x -= vn * (float)dir.x;
//            vel.y -= vn * (float)dir.y;
//        }
//        p.setVelocidad(vel);
//    }
//
//    // Izquierda
//    dif = b.izq.distancia(p.getPosicion(), &dir) - radio;
//    if (dif <= 0)
//    {
//        Vector2D pos = p.getPosicion();
//        pos.x -= (float)(dir.x * dif);
//        pos.y -= (float)(dir.y * dif);
//        p.setPosicion(pos);
//
//        Vector2D vel = p.getVelocidad();
//        float vn = vel.x * (float)dir.x + vel.y * (float)dir.y;
//        if (vn < 0)
//        {
//            vel.x -= vn * (float)dir.x;
//            vel.y -= vn * (float)dir.y;
//        }
//        p.setVelocidad(vel);
//    }
//
//    // Derecha
//    dif = b.dcha.distancia(p.getPosicion(), &dir) - radio;
//    if (dif <= 0)
//    {
//        Vector2D pos = p.getPosicion();
//        pos.x -= (float)(dir.x * dif);
//        pos.y -= (float)(dir.y * dif);
//        p.setPosicion(pos);
//
//        Vector2D vel = p.getVelocidad();
//        float vn = vel.x * (float)dir.x + vel.y * (float)dir.y;
//        if (vn < 0)
//        {
//            vel.x -= vn * (float)dir.x;
//            vel.y -= vn * (float)dir.y;
//        }
//        p.setVelocidad(vel);
//    }
//}
//bool InteraccionArena::colisionMelee(const Personaje& p1, const Personaje& p2)
//{
//    return distancia(p1, p2) < (p1.getRadio() + p2.getRadio());
//}
//
//float InteraccionArena::distancia(const Personaje& p1, const Personaje& p2)
//{
//    float dx = p2.posicion().x - p1.posicion().x;
//    float dy = p2.posicion().y - p1.posicion().y;
//    return std::sqrt(dx * dx + dy * dy);
//}