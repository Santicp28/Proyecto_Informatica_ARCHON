#pragma once
#include "freeglut.h"
class Piezas
{

protected:
    int fila, columna;   // Posición en la matriz (0-8)
    bool esLuz;          // Bando
    float cellSize;      // Tamaño de la casilla
    float boardOffset;   // Para centrar en el mundo OpenGL

public:
    Piezas(int r, int c, bool luz, float offset, float size)
        : fila(r), columna(c), esLuz(luz), boardOffset(offset), cellSize(size) {
    }

    virtual ~Piezas() {}

    // Cada pieza geométrica implementará su propio dibujo
    virtual void dibujar() = 0;

    // Utilidad para convertir coordenadas de matriz a coordenadas de mundo
    void calcularPosicionMundo(float& x, float& y) {
        x = boardOffset + columna * cellSize + (cellSize / 2.0f);
        y = boardOffset + fila * cellSize + (cellSize / 2.0f);
    }
};

