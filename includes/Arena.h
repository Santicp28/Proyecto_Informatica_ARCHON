#pragma once

#include <vector>
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

	struct Proyectil
	{
		Vector2D       posicion; //posicino proyectil
		Vector2D       velocidad;// direccion y velocidad de vuelo
		float          radio = 8.f; //radio de hitbox del proyectil
		double         danio = 15.0; 
		EstadoCombate* propietario = nullptr; //quien lo disparó
	};

protected:
	EstadoCombate jugador1; //Bando luz (Jugador 1 o IA)
	EstadoCombate jugador2; //Bando oscuridad (Jugador 2 o IA)

	std::vector<Proyectil> proyectiles; // lista de proyectiles activos en la arena
	
	BordesArena bordes;

	bool combateTerminado; //si empate o uno muerto
	int  ganadorBando;     // 1 = LUZ, 2 = OSCURIDAD, 0 = en curso


	// daño y cadencia para cada tipo de ataque
	inline static constexpr float VELOCIDAD = 200.0f;//pieza se mueve a 200 píxeles por segundo
	inline static constexpr double DANIO_MELEE = 10.0; // daño por golpe melee
	inline static constexpr float  CADENCIA_MELEE = 1.0f;// segundos entre golpes melee
	inline static constexpr double DANIO_AREA = 20.0;  // daño por segundo
	inline static constexpr double DANIO_PROYECTIL = 15.0;// daño al impactar un proyectil
	inline static constexpr float  CADENCIA_PROYECTIL = 1.0f;
	inline static constexpr float  VELOCIDAD_PROYECTIL = 350.0f; // píxeles/segundo del proyectil
	
	//despachador: lee TipoAtaque de la pieza y llama al método correcto
	//void procesarAtaque(EstadoCombate& atacante, EstadoCombate& defensor, float dt);
	
	//daño continuo mientras el enemigo esté en el radio (banshee/phoenix)
	void procesarArea(EstadoCombate& atacante, EstadoCombate& defensor, float dt);
	
	//dibuja el círculo del combatiente en su posición
	void dibujarCombatiente(const EstadoCombate& c) const;

	//dibuja la barra de vida de una pieza en coordenadas (x,y)
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

