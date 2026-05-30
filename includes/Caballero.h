#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"

class Caballero : public Pieza
{
public:
    Caballero(std::string nombre = "Caballero", TipoPieza tipo = TipoPieza::CABALLERO, Bando b = Bando::LUZ);
 
   
    ~Caballero() { delete golpe; golpe = nullptr; }
};