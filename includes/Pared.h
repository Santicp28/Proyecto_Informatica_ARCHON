#pragma once
#include "Vector2D.h"
#include "Renderer.h"

class Interaccion;

class Pared
{
    friend class Interaccion;
    const Vector2D limite1;
    const Vector2D limite2;
    const Color color;

public:
    Pared(const Vector2D& l1, const Vector2D& l2, const Color& col) :limite1(l1), limite2(l2), color(col) {}
    void dibuja(const Renderer& renderer)const;
    double distancia(const Vector2D& p, Vector2D* pdir = nullptr) const;
};