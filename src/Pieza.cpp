#include "Pieza.h"

bool Pieza::puedeMoverseA(PosicionMatriz destino) {
	PosicionMatriz origen = getPosicionMatriz();

	int distanciaFila = std::abs(destino.fila - origen.fila);
	int distanciaColumna = std::abs(destino.columna - origen.columna);

	switch (tipo_movimiento) {
		case TipoMovimiento::CAMINA:
			return distanciaFila + distanciaColumna <= rango_movimiento;


		case TipoMovimiento::VUELA:
		case TipoMovimiento::TELETRANSPORTE:
			bool movRecto = ((distanciaFila == 0 && distanciaColumna <= rango_movimiento) || (distanciaColumna == 0 && distanciaFila <= rango_movimiento));
			bool movDiagonal = (distanciaFila == distanciaColumna && distanciaFila <= rango_movimiento); //vale cualquiera de las dos
			return movRecto || movDiagonal;
	}
}