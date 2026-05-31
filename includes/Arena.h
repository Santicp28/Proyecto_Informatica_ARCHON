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
#include "Menu.h"

using std::vector;

class Arena
{
	Pieza* jugador1=nullptr; //Bando luz (atacante)
	Pieza* jugador2=nullptr; //Bando oscuridad (defensor)
	Pieza* ultimoGanador = nullptr;
	const Vector2D centro{ Config::sizeMundo * 0.5 };
	const Vector2D posicionInicialJugador1{ {Config::sizeMundo.x * 0.2},{Config::sizeMundo.y * 0.5} };//centro izda
	const Vector2D posicionInicialJugador2{ {Config::sizeMundo.x - posicionInicialJugador1.x},posicionInicialJugador1.y };//centro drcha
	const Vector2D size{ Config::sizeMundo };
	const Bordes bordes{ size * 0.7, centro };
	ListaDisparos listaDisparos;
	ListaObstaculos listaObstaculos;
	Menu menuCombateTerminado;
	bool combateTerminado; //si empate o uno muerto
	int  ganadorBando;     // 1 = LUZ, 2 = OSCURIDAD, 0 = en curso

	void generaObstaculos(int cantidad = 8, unsigned int semilla = 0);
	bool esPosicionReservada(const Vector2D& pos, float margen) const;
	bool esFinAbsoluto = false;
	Bando bandoGanadorAbsoluto = Bando::NINGUNO;
	bool teclas[256]{false};
	bool teclasEspeciales[512]{ false };


public:
	Arena();
	void inicializa(Pieza * p1, Pieza * p2);
	void mueve(float dt);
	void dibuja(const Renderer& renderer) const;
	void tecla(unsigned char key);
	void teclaUP(unsigned char key);
	void teclaEspecial(int key);
	void teclaEspecialUP(int key);
	void setFinAbsoluto(Bando ganador) { esFinAbsoluto = true; bandoGanadorAbsoluto = ganador; }
	void limpiarJugadores() { jugador1 = nullptr; jugador2 = nullptr; }
	bool getFinAbsoluto() const { return esFinAbsoluto; }
	bool terminado() const { return combateTerminado; };

	void resetPosiciones();
	
	Pieza* getGanador() const;
	Pieza* getUltimoGanador() const { return ultimoGanador; }
	

};

