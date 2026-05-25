#pragma once

#include <vector>
#include "Pieza.h"
#include "Bordes.h"
#include "InteraccionArena.h"
#include "Config.h"
using std::vector;
class Arena
{
	Pieza* jugador1; //Bando luz (Jugador 1 o IA)
	Pieza* jugador2; //Bando oscuridad (Jugador 2 o IA)
	Vector2D centro{ Config::sizeMundo * 0.5 };
	Vector2D size{ Config::sizeMundo };
	Bordes bordes{ size * 0.9, centro };

	bool combateTerminado; //si empate o uno muerto
	int  ganadorBando;     // 1 = LUZ, 2 = OSCURIDAD, 0 = en curso
public:
	void inicializa(Pieza * p1, Pieza * p2);
	void mueve(float dt);
	void dibuja() const;
	void tecla(unsigned char key);
	void teclaEspecial(int key);
	bool terminado() const { return combateTerminado; };
	int ganador() const { return ganadorBando; };
	
};

