#pragma once
#include "Vector2D.h"
#include "color.h"

class Interaccion;

class Pared
{
    Vector2D limite1_;
    Vector2D limite2_;
    Color    color_;

public:
    Pared() = default;
    Pared(const Vector2D& l1, const Vector2D& l2, const Color& c);

    void dibuja() const;
    void color(const Color& col) { color_ = col; }

    double distancia(const Vector2D& p, Vector2D* pdir = nullptr) const;

    friend class Interaccion;
};