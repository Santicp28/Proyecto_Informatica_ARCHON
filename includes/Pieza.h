#pragma once
#include "freeglut.h"
#include "Casilla.h"
enum class TipoMovimiento {
    camina,
    vuela,
    teletransporte
};
class Pieza
{
protected:
    Casilla casilla;   // Posición en la matriz (0-8)
    double fuerza;
    double cadencia;
    double vida;
    bool esLuz;          // Bando
    float size;      // Tamaño de la casilla
    TipoMovimiento tipo_movimiento;
    float boardOffset;   // Para centrar en el mundo OpenGL

public:
    Pieza(int r, int c, bool luz, float offset, float size)
        : fila(r), columna(c), esLuz(luz), boardOffset(offset), cellSize(size) {
    }

    virtual ~Pieza() {}

    // Cada pieza geométrica implementará su propio dibujo
    virtual void dibujar() = 0;

    // Utilidad para convertir coordenadas de matriz a coordenadas de mundo
    void calcularPosicionMundo(float& x, float& y) {
        x = boardOffset + columna * cellSize + (cellSize / 2.0f);
        y = boardOffset + fila * cellSize + (cellSize / 2.0f);
    }
};

