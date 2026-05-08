#pragma once

#include "Personaje.h"
class Arena
{
protected:
	Personaje* jugador1;
	Personaje* jugador2;

	bool combateTerminado;
public:
	void inicializa(Personaje* p1, Personaje* p2);
	void mueve(float dt);
	void dibuja();
	bool terminado() const;
	int ganador() const;
	void tecla(unsigned char key);
};

