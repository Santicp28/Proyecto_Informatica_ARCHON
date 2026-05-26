#pragma once
#include "freeglut.h"
#include "Casilla.h"
#include"Renderer.h"
#include"Vector2D.h"
#include "Tipos.h"
#include "ObjetoMovil.h"
class Pieza: public ObjetoMovil
{
	friend class Interaccion;
protected:

	PosicionMatriz posicionMatriz; // Posición en la matriz (fila, columna)
    Vector2D posicionArena;
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
    virtual void setPosicionArena(const Vector2D& posicion) { posicionArena = posicion; }
    virtual bool mover(PosicionMatriz destino) = 0; //DESARROLLAR PARA CADA PIEZA !!!!!!!

    PosicionMatriz getPosicionMatriz() const { return posicionMatriz; }
    // Utilidad para convertir coordenadas de matriz a coordenadas de mundo
   /* void calcularPosicionMundo(Vector2D esquina_arriba_izda, double size_celda) {
        x = boardOffset + columna * cellSize + (cellSize / 2.0f);
        y = boardOffset + fila * cellSize + (cellSize / 2.0f);
    }*/

    Pieza(double sizeradio = 1.0, Vector2D pos = {}, Vector2D vel = {}, Vector2D acel = {}): ObjetoMovil(pos, vel, acel, sizeradio) {}
};
