#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"

class Caballero : public Pieza
{
public:
    Caballero(std::string nombre = "Caballero", Bando b = Bando::AZUL);
 
   
    ~Caballero() { delete golpe; golpe = nullptr; }
};