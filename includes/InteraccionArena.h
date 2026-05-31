#pragma once
#include "Pieza.h"
#include "Bordes.h"
#include "Disparo.h"
#include "Pared.h"
#include "Obstaculo.h"
class InteraccionArena
{
	friend class Disparo;
	friend class Pieza;
	friend class Obstaculo;
	static void resolverBorde(ObjetoMovil& obj, const Pared& pared);
    static void resolverColision(ObjetoMovil& obj1, ObjetoMovil& obj2);
public:
	static void colision(Pieza& p, const Bordes& b);
	static void colision(Pieza& p1, Pieza& p2);
	static void colision(Pieza& p, const Obstaculo& obs);
	static bool colision(const Disparo& d, const Bordes& b);
	static bool colision(const Disparo& d, const Pieza& p);
	static bool colision(const Disparo& d, const Obstaculo& obs);
	static bool colision(const GolpeAtaque& golpe, const Vector2D& posAtacante,const Vector2D& dir, const Pieza& defensor);
	static bool colision(const GritoArea& grito, const Vector2D& posBanshee, const Pieza& defensor);
};