#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Dragon : public Pieza
{
public:
    Dragon(std::string nombre = "Dragon", TipoPieza tipo = TipoPieza::DRAGON, Bando b = Bando::OSCURIDAD);

};