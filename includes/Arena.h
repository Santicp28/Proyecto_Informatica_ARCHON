#pragma once

#include "Pieza.h"
#include "BordesArena.h"
#include "InteraccionArena.h"
class Arena
{
	// agrupa todo lo físico de un combatiente en un solo sitio
	struct EstadoCombate
	{
		Pieza* pieza = nullptr; // stats del tablero (ataque, bando...)
		
		//SI PONEMOS getVida en pieza quitamos vida de aqui
		double vida = 100.0;  // valor fijo, no viene de Pieza
		double vidaMax = 100.0;  // valor fijo, no viene de Pieza
		//SI PONEMOS FISICAS EN PIEZA QUITAR VECTOR 2D
		Vector2D posicion;      // posición física
		Vector2D velocidad;     // velocidad de movimiento
		
		//ESTOS SE QUEDAN
		float cooldown = 0.f;   // tiempo hasta poder atacar de nuevo
		bool atacar = false;	// flag de input de ataque
		float radio = 20.f;		// tamaño de la hitbox circular
	};
protected:
	EstadoCombate jugador1; //Bando luz (Jugador 1 o IA)
	EstadoCombate jugador2; //Bando oscuridad (Jugador 2 o IA)
	
	BordesArena bordes;

	bool combateTerminado;
	int  ganadorBando;     // 1 = LUZ, 2 = OSCURIDAD, 0 = en curso

	inline static constexpr float VELOCIDAD = 200.0f;//pieza se mueve a 200 píxeles por segundo


	void procesarAtaque(EstadoCombate& atacante, EstadoCombate& defensor);
	void dibujarCombatiente(const EstadoCombate& c) const;
	void dibujarBarraVida(const Pieza* p, float x, float y) const;

public:

	//Constructor con inicializador
	Arena() : combateTerminado(false), ganadorBando(0) {}
	//Arena recibe punteros a los personajes creaods por Juego / Tablero
	void inicializa(Pieza * p1, Pieza * p2);
	void mueve(float dt);
	void dibuja() const;
	void tecla(unsigned char key);
	void teclaEspecial(int key);
	bool terminado() const { return combateTerminado; };
	int ganador() const { return ganadorBando; };
	
};

