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
    double ataque;
    double velocidad;
    double cadencia;
    double vida;
    double velocidad_ataque;
    Bando bando;      // Bando
    TipoMovimiento tipo_movimiento;
    int rango_movimiento;
    Color color;
public:
    virtual void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const = 0;

    Pieza(Ataque at, Vida vi, Velocidad vel, Cadencia cad, Velocidad_ataque vel_at, Rango ra, Bando b, TipoMovimiento tm)
        :
        posicionMatriz{ 0, 0 },
        ataque(0.0),
        velocidad(0.0),
        cadencia(0.0),
        vida(0.0),
        velocidad_ataque(0.0),
        bando(b),
        tipo_movimiento(tm),
        rango_movimiento(0) {

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

        // --- RANGO (Casillas que puede avanzar en tablero) --- 
        if (ra == Rango::CORTO) rango_movimiento = 3;
        else if (ra == Rango::MEDIO) rango_movimiento = 4;
        else if (ra == Rango::LARGO) rango_movimiento = 5;
    }

    void setPosicionMatriz(unsigned int fila, unsigned int columna) {
        posicionMatriz.fila = fila;
        posicionMatriz.columna = columna;
    }

    bool puedeMoverseA(PosicionMatriz destino);

    PosicionMatriz getPosicionMatriz() const { return posicionMatriz; }
    TipoMovimiento getTipoMovimiento() const { return tipo_movimiento; }

    Bando getBando() const { return bando; }




    virtual void setPosicionArena(const Vector2D& posicion) { posicionArena = posicion; }
    Pieza(double sizeradio = 1.0, Vector2D pos = {}, Vector2D vel = {}, Vector2D acel = {}): ObjetoMovil(pos, vel, acel, sizeradio) {}
};
