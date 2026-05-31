#pragma once
#include "Vector2D.h"
#include "Renderer.h"
class GritoArea
{
    enum class Estado { INACTIVO, ACTIVO, COOLDOWN };
    Estado estado = Estado::INACTIVO;
	double tiempoAcumulado = 0.0;
	double tiempoEntreDanio = 0.0; 
    double radio;
    double duracion;
    static constexpr double INTERVALO_DANIO = 0.5;
    const char* sprite = nullptr;
public:
	GritoArea(double radio = 100.0, double duracion = 2.0, const char* spr = nullptr) : radio(radio), duracion(duracion), sprite(spr) {}
    bool activar();
    bool actualizar(double dt, double cadencia); 
    bool estaActivo() const { return estado == Estado::ACTIVO; }
    void resetear() { estado = Estado::INACTIVO; tiempoAcumulado = 0.0; }
    bool dentroDelArea(const Vector2D& posBanshee, const Vector2D& posObjetivo) const;
    void dibuja(const Renderer& renderer, const Vector2D& pos) const;

};

