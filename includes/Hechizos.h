#pragma once
#include "ListaPiezas.h"
#include "Pieza.h"
#include "Tipos.h"

struct HechizoQueVoyAUsar {
	bool cambiarCiclo = false;
	bool curar = false;
	bool encarcelar = false;
	bool vasoDeAgua = false;
	bool tp = false;
	bool intercambiar = false;
};

namespace Hechizos {
	//hechizos sin casilla
	void cambiarCiclo(CicloAZUL_A_ROJO& ciclo, int& contador, Casilla casillas[9][9]);

	//hechizos de 1 casilla
	void curar(Pieza& p);
	void encarcelar(ListaPiezas& l, Pieza& p);
	void vasoDeAgua(Pieza& p);

	//hechizos de 2 casillas
	void tp(const PosicionMatriz& origen, const PosicionMatriz& destino, ListaPiezas& lista);
	void intercambiar(const PosicionMatriz& origen, const PosicionMatriz& destino, ListaPiezas& lista);


};
