#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include "Pieza.h"
#include "Bordes.h"
#include "InteraccionArena.h"
#include "Config.h"
#include "ListaDisparos.h"
#include "ListaObstaculos.h"
#include "Grafarena.h"

using std::vector;

class Arena
{
	Pieza* jugador1=nullptr; //Bando luz (atacante)
	Pieza* jugador2=nullptr; //Bando oscuridad (defensor)
	const Vector2D centro{ Config::sizeMundo * 0.5 };
	const Vector2D posicionInicialJugador1{ {Config::sizeMundo.x * 0.2},{Config::sizeMundo.y * 0.5} };//centro izda
	const Vector2D posicionInicialJugador2{ {Config::sizeMundo.x - posicionInicialJugador1.x},posicionInicialJugador1.y };//centro drcha
	const Vector2D size{ Config::sizeMundo };
	const Vector2D centroArena{ centro.x , centro.y - size.y * 0.03 };
	const Bordes bordes{ {size.x * 0.78, size.y * 0.75}, centroArena };
	ListaDisparos listaDisparos;
	ListaObstaculos listaObstaculos;

	bool combateTerminado; //si empate o uno muerto
	int  ganadorBando;     // 1 = LUZ, 2 = OSCURIDAD, 0 = en curso

	void generaObstaculos(int cantidad = 8, unsigned int semilla = 0);
	bool esPosicionReservada(const Vector2D& pos, float margen) const;


	bool teclas[256]{false};
	bool teclasEspeciales[512]{ false };

	float tiempoDesdeUltimaGeneracion = 0.0f;
	float intervaloGeneracion = 2.0f; // segundos entre cada regeneración
	int cantidadObstaculos = 8;
	static constexpr int maxObstaculos = 22;

public:
	void inicializa(Pieza * p1, Pieza * p2);
	void mueve(float dt);
	void dibuja(const Renderer& renderer) const;
	void tecla(unsigned char key);
	void teclaUP(unsigned char key);
	void teclaEspecial(int key);
	void teclaEspecialUP(int key);

	bool terminado() const { return combateTerminado; };

	void resetPosiciones();
	
	Pieza* getGanador() const;
	Pieza* getJugador1() const { return jugador1; }
	Pieza* getJugador2() const { return jugador2; }

};

