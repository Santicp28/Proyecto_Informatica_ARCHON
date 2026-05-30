#pragma once
#include "freeglut.h"
#include "Casilla.h"
#include"Renderer.h"
#include"Vector2D.h"
#include "Tipos.h"
#include "ObjetoMovil.h"
#include"GolpeAtaque.h"
#include "GritoArea.h"
#include <string>

class Disparo;
class Pieza: public ObjetoMovil
{
    friend class InteraccionArena;
protected:

	std::string nombre;
	PosicionMatriz posicionMatriz; // Posición en la matriz (fila, columna)
    Vector2D posicionArena;
    double ataque;
    double velocidadMax;
    double cadencia;
    double vida_maxima;
	double vida_actual;
    double defensa;
    double velocidad_ataque;
    Bando bando;      // Bando
    TipoMovimiento tipo_movimiento;
    int rango_movimiento;
    Color color;
    GolpeAtaque* golpe = nullptr;
    GritoArea* grito = nullptr;
	
	bool protegidoContraHechizos = false; 
    bool golpeConectado = false;
    double tiempoDesdeUltimoDisparo = 999.0;
public:
    bool atacar{ false };

    virtual void dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const = 0;

    virtual const char* getSpriteAtaque() const { return nullptr; }

    Pieza(std::string nom, Ataque at, Vida_maxima vi, Velocidad vel, Cadencia cad, Velocidad_ataque vel_at, Rango ra, Bando b, TipoMovimiento tm)
        :ObjetoMovil({}, {}, {}, 30.0)
       ,nombre(nom),
        posicionMatriz{ 0, 0 },
        ataque(0.0),
        velocidadMax(0.0),
        cadencia(0.0),
        vida_maxima(0.0),
        defensa(1.0), //por defecto no reduce daño, pero cuando está en una casilla de su color aumenta y recibe menos daño
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

        // --- VIDA MAXIMA ---
        if (vi == Vida_maxima::CORTA) vida_maxima = 50.0;
        else if (vi == Vida_maxima::MODERADA) vida_maxima = 100.0;
        else if (vi == Vida_maxima::ALTA) vida_maxima = 150.0;
        else if (vi == Vida_maxima::MUYALTA) vida_maxima = 200.0;
        else if (vi == Vida_maxima::VARIABLE) vida_maxima = 100.0;

		vida_actual = vida_maxima; 

        // --- VELOCIDAD (Desplazamiento) ---
        if (vel == Velocidad::BAJA) velocidadMax = 60.0;
        else if (vel == Velocidad::NORMAL) velocidadMax = 80.0;
        else if (vel == Velocidad::VARIABLE) velocidadMax = 80.0;

        // --- CADENCIA (Tiempo entre disparos) ---
        if (cad == Cadencia::MUYRAPIDA) cadencia = 0.2;
        else if (cad == Cadencia::PROMEDIO) cadencia = 1.0;
        else if (cad == Cadencia::RAPIDA) cadencia = 1.5;
        else if (cad == Cadencia::LENTA) cadencia = 2.5;
        else if (cad == Cadencia::VARIABLE) cadencia = 2;

        // --- VELOCIDAD_ATAQUE (Movimiento del proyectil) ---
        if (vel_at == Velocidad_ataque::LENTO) velocidad_ataque = 50.0; //5
        else if (vel_at == Velocidad_ataque::NORMAL) velocidad_ataque = 150.0;//8
        else if (vel_at == Velocidad_ataque::RAPIDO) velocidad_ataque = 250.0;//12
        else if (vel_at == Velocidad_ataque::INSTANTANEO) velocidad_ataque = 300.0;
        else if (vel_at == Velocidad_ataque::VARIABLE) velocidad_ataque = 150.0;

        // --- RANGO (Casillas que puede avanzar en tablero) --- 
        if (ra == Rango::CORTO) rango_movimiento = 3;
        else if (ra == Rango::MEDIO) rango_movimiento = 4;
        else if (ra == Rango::LARGO) rango_movimiento = 5;
    }

    


    // --- SETTERS ----
    void setDefensa(double def) { defensa = def; }
    virtual void setPosicionArena(const Vector2D& posicion) { posicion_ = posicion; }
	void setProteccionContraHechizos(bool protegido) { protegidoContraHechizos = protegido;}

	void curar(double cantidad) { 
        if ((vida_actual + cantidad) > vida_maxima) vida_actual = vida_maxima; 
		else vida_actual += cantidad;
    }

    void setPosicionMatriz(unsigned int fila, unsigned int columna) {
        posicionMatriz.fila = fila;
        posicionMatriz.columna = columna;
    }
    void recibirDanio(double cantidad) {
        vida_actual -= cantidad / defensa;
        if (vida_actual < 0) vida_actual = 0;
        printf("vida actual: %f\n", vida_actual);
    }

    // --- GETTERS ----
    PosicionMatriz getPosicionMatriz() const { return posicionMatriz; }
    Bando getBando() const { return bando; }
	bool estaProtegidoContraHechizos() const { return protegidoContraHechizos; }

	std::string getNombre() const { return nombre; }
	double getVidaMax() const { return vida_maxima; }
	double getVidaActual() const { return vida_actual; }
	double getAtaque() const { return ataque; }
	double getDefensa() const { return defensa; }
	double getVelocidad() const { return velocidadMax; }
    double getCadencia() const { return cadencia; }
    double getVelocidadAtaque() const { return velocidad_ataque; }
	int getRangoMovimiento() const { return rango_movimiento; }
    TipoMovimiento getTipoMovimiento() const { return tipo_movimiento; }
    double getDistanciaCadencia() const { return cadencia; }

    std::string getTipoMovimientoString() const {
		if (tipo_movimiento == TipoMovimiento::CAMINA) return "Camina";
        else if(tipo_movimiento == TipoMovimiento::VUELA) return "Vuela";
        else return "Teletransporte";
	}

    // --- FLAGS ----
    bool puedeMoverseA(PosicionMatriz destino);
    bool puedeDisparar();
    bool estaMuerto() const { return vida_actual <= 0; }
    bool esAtaqueMelee() const { return golpe != nullptr; }
    bool esAtaqueArea() const { return grito != nullptr; }
    bool golpeActivo() const { return golpeConectado; }
    bool golpeYaConecto = false; //un golpe por swing

    //double getArmadura() const { return armadura; }    //double getDanio() const { return ataque; }
   
    const Vector2D& getDireccion() const { return direccion; }
    const GolpeAtaque& getGolpe() const { return *golpe; }
    GritoArea& getGrito() { return *grito; }
    void mueve(double t) override {
        ObjetoMovil::mueve(t);
        tiempoDesdeUltimoDisparo += t;
    }
    void actualizarGolpe(double dt);
    void resetEstadoArena();
};

