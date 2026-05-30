#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Banshee : public Pieza 
{
public:
    Banshee(std::string nombre = "Banshee", TipoPieza tipo = TipoPieza::BANSHEE, Bando b = Bando::OSCURIDAD);

   
};

