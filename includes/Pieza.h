#pragma once
#include "freeglut.h"
#include "Casilla.h"
#include"Renderer.h"
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
enum class Cadencia {
    VARIABLE,
    MUYRAPIDA,
    RAPIDA,
    PROMEDIO,
    LENTA
};
enum class Velocidad {
    VARIABLE,
    NORMAL,
    BAJA
};
enum class Vida {
    VARIABLE,
    MUYALTA,
    ALTA,
    MODERADA,
    CORTA,
    
};
enum class Ataque {
    VARIABLE,
    MUYALTO,
    ALTO,
    MODERADO,
    BAJO
};
enum class Velocidad_ataque {
    VARIABLE,
    INSTANTANEO,
    RAPIDO,
    NORMAL,
    LENTO
};
class Pieza
{
protected:
    Casilla casilla;   // Posición en la matriz (0-8)
    double ataque;
    double velocidad;

	PosicionMatriz posicionMatriz; // Posición en la matriz (fila, columna)
    double fuerza;
    double cadencia;
    double vida;
    double velocidad_ataque;
    Bando bando;      // Bando
    TipoMovimiento tipo_movimiento;
    Color color;
public:
    virtual void dibuja(Vector2D esquina_arriba_izda,double size_celda);
    virtual void dibujarForma() = 0;

    Pieza(Ataque at, Vida vi, Velocidad vel, Cadencia cad, Velocidad_ataque vel_at, Bando b, TipoMovimiento tm)
        : bando(b), tipo_movimiento(tm) {

        // --- FUERZA (Ataque) ---
        if (at == Ataque::BAJO) ataque = 25.0;
        else if (at == Ataque::MODERADO) ataque = 50.0;
        else if (at == Ataque::ALTO) ataque = 75.0;
        else if (at == Ataque::MUYALTO) ataque = 100.0;
        else if (at == Ataque::VARIABLE) ataque = 50.0; // Valor base

        // --- VIDA ---
        if (vi == Vida::CORTA) vida = 50.0;
        else if (vi == Vida::MODERADA) vida = 100.0;
        else if (vi == Vida::ALTA) vida = 150.0;
        else if (vi == Vida::MUYALTA) vida = 200.0;
        else if (vi == Vida::VARIABLE) vida = 100.0;

        // --- VELOCIDAD (Desplazamiento) ---
        if (vel == Velocidad::BAJA) velocidad = 4.0;
        else if (vel == Velocidad::NORMAL) velocidad = 6.0;
        else if (vel == Velocidad::VARIABLE) velocidad = 6.0;

        // --- CADENCIA (Tiempo entre disparos) ---
        if (cad == Cadencia::MUYRAPIDA) cadencia = 0.2;
        else if (cad == Cadencia::PROMEDIO) cadencia = 1.5;
        else if (cad == Cadencia::RAPIDA) cadencia = 2.0;
        else if (cad == Cadencia::LENTA) cadencia = 2.5;
        else if (cad == Cadencia::VARIABLE) cadencia = 1.5;

        // --- VELOCIDAD_ATAQUE (Movimiento del proyectil) ---
        if (vel_at == Velocidad_ataque::LENTO) velocidad_ataque = 5.0;
        else if (vel_at == Velocidad_ataque::NORMAL) velocidad_ataque = 8.0;
        else if (vel_at == Velocidad_ataque::RAPIDO) velocidad_ataque = 12.0;
        else if (vel_at == Velocidad_ataque::INSTANTANEO) velocidad_ataque = 25.0;
        else if (vel_at == Velocidad_ataque::VARIABLE) velocidad_ataque = 8.0;
    }
    
    void setPosicionMatriz(unsigned int fila, unsigned int columna) {
        posicionMatriz.fila = fila;
        posicionMatriz.columna = columna;
	}
    virtual bool mover(PosicionMatriz destino) = 0; //DESARROLLAR PARA CADA PIEZA !!!!!!!


    PosicionMatriz getPosicionMatriz() const { return posicionMatriz; }
    // Utilidad para convertir coordenadas de matriz a coordenadas de mundo
   /* void calcularPosicionMundo(Vector2D esquina_arriba_izda, double size_celda) {
        x = boardOffset + columna * cellSize + (cellSize / 2.0f);
        y = boardOffset + fila * cellSize + (cellSize / 2.0f);
    }*/

};

