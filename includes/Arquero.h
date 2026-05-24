#pragma once
#include "Pieza.h"
#include "TiposPiezas.h"

class Arquero : public Pieza
{
public:
	Arquero(Bando b = Bando::LUZ);
	void dibuja();
};

