#pragma once
#include "freeglut.h"
#include"Color.h"
#include"Vector2D.h"
#include "Tipos.h"

class Pieza
{
	friend class Interaccion;
protected:

	PosicionMatriz posicionMatriz; // Posición en la matriz (fila, columna)
    double fuerza;
    double cadencia;
    double vida;
    Bando bando;      // Bando
    TipoMovimiento tipo_movimiento;
    Color color;
public:
    virtual void dibuja(Vector2D esquina_arriba_izda,double size_celda);
    virtual void dibujarForma() = 0;
    void setPosicionMatriz(unsigned int fila, unsigned int columna) {
        posicionMatriz.fila = fila;
        posicionMatriz.columna = columna;
	}
    PosicionMatriz getPosicionMatriz() const { return posicionMatriz; }
    // Utilidad para convertir coordenadas de matriz a coordenadas de mundo
   /* void calcularPosicionMundo(Vector2D esquina_arriba_izda, double size_celda) {
        x = boardOffset + columna * cellSize + (cellSize / 2.0f);
        y = boardOffset + fila * cellSize + (cellSize / 2.0f);
    }*/

    
};

