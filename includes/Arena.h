//#pragma once
//
//#include "Personaje.h"
//#include "BordesArena.h"
//#include "InteraccionArena.h"
//
//class Arena
//{
//protected:
//	Personaje* jugador1;//Bando luz (Jugador 1 o IA)
//	Personaje* jugador2;//Bando oscuridad (Jugador 2 o IA)
//
//	BordesArena bordes;
//
//	bool combateTerminado;
//	int  ganadorBando;     // 1 = LUZ, 2 = OSCURIDAD, 0 = en curso
//
//	void dibujarBarraVida(const Personaje* p, float x, float y) const;
//
//public:
//
//	Constructor con inicializador
//	Arena() :jugador1(nullptr), jugador2(nullptr), combateTerminado(false), ganadorBando(0) {}
//	Arena recibe punteros a los personajes creaods por Juego/Tablero
//	void inicializa(Personaje* p1, Personaje* p2);
//
//	void mueve(float dt);
//	void dibuja() const;
//	void tecla(unsigned char key);
//	void teclaEspecial(unsigned char key);
//
//	bool terminado() const { return combateTerminado; };
//	int ganador() const { return ganadorBando; };
//	
//};
//
