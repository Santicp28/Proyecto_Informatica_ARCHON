#include "GritoArea.h"
#include <cmath>

bool GritoArea::activar() {
    if (estado == Estado::INACTIVO) {
        estado = Estado::ACTIVO;
        tiempoAcumulado = 0.0;
		tiempoEntreDanio = 0.0;  
        return true; 
    }
    return false; 
}

bool GritoArea::actualizar(double dt, double cadencia) {
    if (estado == Estado::INACTIVO) return false;

    tiempoAcumulado += dt;

    if (estado == Estado::ACTIVO) {
        tiempoEntreDanio += dt;
        if (tiempoAcumulado >= duracion) {
            estado = Estado::COOLDOWN;
            tiempoAcumulado = 0.0;
            tiempoEntreDanio = 0.0;
            return false;
        }
        if (tiempoEntreDanio >= INTERVALO_DANIO) {
            tiempoEntreDanio = 0.0;
            return true; 
        }
        return false;
    }

    if (estado == Estado::COOLDOWN) {
        if (tiempoAcumulado >= cadencia) {
            estado = Estado::INACTIVO;
            tiempoAcumulado = 0.0;
        }
    }

    return false;
}
bool GritoArea::dentroDelArea(const Vector2D& posBanshee, const Vector2D& posObjetivo) const {
    Vector2D vecHasta = posObjetivo - posBanshee;
    return vecHasta.modulo() <= radio+30;
}

void GritoArea::dibuja(const Renderer& renderer, const Vector2D& pos) const {
    if (sprite) {
        renderer.dibujaSprite(sprite, pos, radio * 2, radio * 2); 
        return;
    }

    const int segmentos = 32;
    const double paso = 2.0 * Config::PI / segmentos;

    for (int i = 0; i < segmentos; i++) {
        double angulo1 = i * paso;

        Vector2D p1 = { pos.x + radio * cos(angulo1), pos.y + radio * sin(angulo1) }; 
        renderer.dibujaOvalo(p1, { 1.0f, 0.2f, 0.0f }, 5.0, 5.0);
    }
}