#pragma once
#include "freeglut.h"
#include "Casilla.h"
#include"Color.h"
#include"Vector2D.h"
enum class TipoMovimiento {
    CAMINA,
    VUELA,
    TELETRANSPORTE
};
enum class Bando {
    LUZ,
    OSCURIDAD
};
class Pieza
{
protected:
    Casilla casilla;   // Posición en la matriz (0-8)
    double fuerza;
    double cadencia;
    double vida;
    Bando bando;      // Bando
    TipoMovimiento tipo_movimiento;
    Color color;
public:
    virtual void dibuja(Vector2D esquina_arriba_izda,double size_celda);
    virtual void dibujarForma() = 0;
    // Utilidad para convertir coordenadas de matriz a coordenadas de mundo
    void calcularPosicionMundo(Vector2D esquina_arriba_izda, double size_celda) {
        x = boardOffset + columna * cellSize + (cellSize / 2.0f);
        y = boardOffset + fila * cellSize + (cellSize / 2.0f);
    }
};

