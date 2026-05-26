#pragma once

#include <vector>
#include "Pieza.h"
#include "BordesArena.h"
#include "InteraccionArena.h"
class Arena
{
	

protected:
	BordesArena bordes;

	bool combateTerminado; //si empate o uno muerto
	int  ganadorBando;     // 1 = LUZ, 2 = OSCURIDAD, 0 = en curso

public:

	//Constructor con inicializador
	Arena() : combateTerminado(false), ganadorBando(0) {}
	
	//Arena recibe punteros a los personajes creaods por Juego / Tablero
	void inicializa(Pieza * p1, Pieza * p2);
	
	void mueve(float dt);
	void dibuja() const;
	void tecla(unsigned char key);
	void teclaUP(unsigned char key);
	void teclaEspecial(int key);
	void teclaEspecialUP(int key);

	bool terminado() const { return combateTerminado; };
	int ganador() const { return ganadorBando; };
	
};

