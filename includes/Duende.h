#pragma once
#include "Pieza.h"
#include "Grafpiezas.h"
class Duende : public Pieza
{
public:
    Duende(std::string nombre = "Duende", Bando b = Bando::ROJO);


    ~Duende() { delete golpe; golpe = nullptr; }
};