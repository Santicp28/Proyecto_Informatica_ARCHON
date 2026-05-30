#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Fenix : public Pieza
{
public:
    Fenix(std::string nombre = "Fenix", TipoPieza tipo = TipoPieza::FENIX, Bando b = Bando::LUZ);

};
