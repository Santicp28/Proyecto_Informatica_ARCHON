#pragma once
#include "Pieza.h"
class Djinni : public Pieza
{
public:
    Djinni(std::string nombre = "Djinni", Bando b = Bando::LUZ);
    
    void dibuja(const Renderer& renderer,const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const override;};
