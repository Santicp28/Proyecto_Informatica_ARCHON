#pragma once
#include "Pieza.h"
#include "Bordes.h"
#include "Disparo.h"
#include "Pared.h"
class InteraccionArena
{
	friend class Disparo;
	friend class Pieza;
	static void resolverBorde(ObjetoMovil& obj, const Pared& pared);
	static void resolverColision(ObjetoMovil& obj1, ObjetoMovil& obj2);
public:
  static void colision(Pieza& p, const Bordes& b);
  static bool colision(Disparo& d, const Bordes& b);
  static void colision(Pieza& p1, Pieza& p2);
  static bool colision(const Disparo& d, const Pieza& p);
  //// static bool colision(const Disparo& d, const Barrera& b);
  // static double distancia(const Vector2D& pos1, const Vector2D& pos2);
  // static void  procesarAtaque(Pieza& atacante, double& cooldown, Pieza& defensor);
 
};