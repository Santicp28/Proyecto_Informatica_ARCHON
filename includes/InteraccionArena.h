#pragma once
#include "Pieza.h"
#include "BordesArena.h"

class InteraccionArena
{
public:

    //SIN FISICA EN PIEZA
    static void rebote(Vector2D& pos, Vector2D& vel, float radio, const BordesArena& bordes);
    static float distancia(const Vector2D& pos1, const Vector2D& pos2);
    static bool colisionMelee(const Vector2D& pos1, float radio1, const Vector2D& pos2, float radio2);
    static void  procesarAtaque(Pieza& atacante, float& cooldown, Pieza& defensor);
    //CON FISICA EN PIEZA
   /* 
   static void rebote(Pieza& p, const BordesArena& b);
   static bool colisionMelee(const Pieza& p1, const Pieza& p2);
   static float distancia(const Pieza& p1, const Pieza& p2);
   static void  procesarAtaque(Pieza& atacante, float& cooldown, Pieza& defensor);
   */
  
};