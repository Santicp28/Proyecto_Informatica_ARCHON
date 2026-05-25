#pragma once
#include "Pared.h"

class InteraccionArena;

class BordesArena
{
    // Tamaño total de la ventana de juego
    inline static constexpr Vector2D SizeArena{ 800, 600 };
    // Grosor del margen desde el borde de la ventana hasta la pared
    inline static constexpr double MARGEN = 50.0;
    // Coordenadas de las 4 paredes calculadas automáticamente desde SizeArena
    // Si se cambia SizeArena, las paredes se actualizan solas
    inline static constexpr double X_MIN = MARGEN;
    inline static constexpr double X_MAX = SizeArena.x - MARGEN;
    inline static constexpr double Y_MIN = MARGEN;
    inline static constexpr double Y_MAX = SizeArena.y - MARGEN;

    // Cada pared se define con dos puntos (inicio y fin) y un color
    Pared suelo{ {X_MIN, Y_MIN}, {X_MAX, Y_MIN}, {100, 80, 30} };
    Pared techo{ {X_MIN, Y_MAX}, {X_MAX, Y_MAX}, {100, 80, 30} };
    Pared izq{ {X_MIN, Y_MIN}, {X_MIN, Y_MAX}, {100, 80, 30} };
    Pared dcha{ {X_MAX, Y_MIN}, {X_MAX, Y_MAX}, {100, 80, 30} };
public: 
    void dibuja() const;
    friend class InteraccionArena;
   

};

