#pragma once
#include "Pieza.h"
class Arquero : public Pieza
{
public:
	Arquero(Bando b = Bando::LUZ);
	void dibuja();
};

