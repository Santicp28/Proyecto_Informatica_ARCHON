#include "Pieza.h"
#include <algorithm>

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
    printf("[DISPARO] atacar=%d esAtaqueMelee=%d tiempoDesde=%.2f cadencia=%.2f\n",
        atacar, esAtaqueMelee(), tiempoDesdeUltimoDisparo, cadencia);

	if (!atacar) return false; 
    if (esAtaqueMelee()) return false;
    //if (esAtaqueArea())return false;
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
//
//void Pieza::actualizarGolpe(double dt)
//{
//    if (!golpe) return;
//    bool yaEstabaExtendido = golpe->getAngulo() <= 10.0;
//    golpe->actualizar(atacar, dt);
//    bool ahoraExtendido = golpe->getAngulo() <= 10.0;
//    golpeConectado = (!yaEstabaExtendido && ahoraExtendido);
//
//    printf("[GOLPE] angulo=%.2f atacar=%d golpeConectado=%d golpeYaConecto=%d\n",
//        golpe->getAngulo(), atacar, golpeConectado, golpeYaConecto);
//
//    if (golpe->getAngulo() >= 44.0)
//        golpeYaConecto = false;
//}