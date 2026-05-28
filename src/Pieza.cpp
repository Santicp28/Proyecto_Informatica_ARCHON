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

	if (!atacar) return false; 
    if (tiempoDesdeUltimoDisparo >= cadencia) {
		tiempoDesdeUltimoDisparo = 0.0; 
		return true;
    }

	return false;
}
