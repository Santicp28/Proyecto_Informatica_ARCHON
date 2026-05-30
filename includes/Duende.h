#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Duende : public Pieza
{
public:
    Duende(std::string nombre = "Duende", TipoPieza tipo = TipoPieza::DUENDE, Bando b = Bando::OSCURIDAD);


    ~Duende() { delete golpe; golpe = nullptr; }
};