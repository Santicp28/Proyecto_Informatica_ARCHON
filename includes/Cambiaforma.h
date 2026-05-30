#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Cambiaforma : public Pieza
{
public:
    Cambiaforma(std::string nombre = "Cambiaforma", TipoPieza tipo = TipoPieza::CAMBIAFORMA, Bando b = Bando::OSCURIDAD);
    

};