#include "Pieza.h"
#include <algorithm>

void Pieza::dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites, const Vector2D& centro, double ancho, double alto) const {

	double escalaStatus = 0.6;

    //status
    if (!enArena){
        if (mojada) renderer.dibujaCuadrado(contenedorSprites.spriteStatusMojada, centro,Config::cyan, {ancho * escalaStatus, alto * escalaStatus});
        if (encarcelada) renderer.dibujaCuadrado(contenedorSprites.spriteStatusEncarcelada, centro,Config::grisClaro, {ancho * escalaStatus, alto * escalaStatus});
    }
}



bool Pieza::puedeMoverseA(PosicionMatriz destino) {
    PosicionMatriz origen = getPosicionMatriz();

    int distanciaFila = std::abs(destino.fila - origen.fila);
    int distanciaColumna = std::abs(destino.columna - origen.columna);

    switch (tipo_movimiento) {
    case TipoMovimiento::CAMINA:
        return distanciaFila + distanciaColumna <= rango_movimiento;


    case TipoMovimiento::VUELA:
    {
        int distancia = std::max(distanciaFila, distanciaColumna);

        return distancia <= rango_movimiento;
    }

    case TipoMovimiento::TELETRANSPORTE:
    {
        int distancia = std::max(distanciaFila, distanciaColumna);

        return distancia <= rango_movimiento;
    }

    default:
        return false;
    }
}    
bool Pieza::puedeDisparar() {

	if (!atacar) return false; 
    if (esAtaqueMelee()) return false;
    if (esAtaqueArea())return false;
    if (tiempoDesdeUltimoDisparo >= cadencia) {
		tiempoDesdeUltimoDisparo = 0.0; 
		return true;
    }

	return false;
}


void Pieza::actualizarGolpe(double dt)
{
    if (!golpe) return;
    bool yaEstabaExtendido = golpe->getAngulo() <= 10.0;
    golpe->actualizar(atacar, dt);
    bool ahoraExtendido = golpe->getAngulo() <= 10.0;
    golpeConectado = (!yaEstabaExtendido && ahoraExtendido);
    if (golpe->getAngulo() >= 45 - 1.0)  
        golpeYaConecto = false;
}

void Pieza::resetEstadoArena()
{
    velocidad_ = { 0, 0 };
    atacar = false;
    golpeYaConecto = false;
    tiempoDesdeUltimoDisparo = 999.0;
}
