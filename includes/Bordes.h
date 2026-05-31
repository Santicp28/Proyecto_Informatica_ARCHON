#pragma once
#include "Pared.h"
#include "Vector2D.h"
#include "Renderer.h"
#include "ContenedorSprites.h"

class InteraccionArena;

class Bordes
{
    friend class InteraccionArena;

    const Pared suelo;
    const Pared techo;
    const Pared izq;
    const Pared dcha;
    const Color color{ 0.0f,0.0f,0.5f };
public: 
    Bordes(const Vector2D& size, const Vector2D& centro);
    void dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites) const;
};

