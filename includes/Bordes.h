#pragma once
#include "Pared.h"
#include "Vector2D.h"
#include "Renderer.h"

class InteraccionArena;

class Bordes
{
    friend class InteraccionArena;

    Pared suelo;
    Pared techo;
    Pared izq;
    Pared dcha;
    Color color{ 0.0f,0.0f,0.5f };
public: 
    Bordes(const Vector2D& size, const Vector2D& centro);
    void dibuja(const Renderer& renderer)const;
};

