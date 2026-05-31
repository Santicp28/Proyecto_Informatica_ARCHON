#include "Pieza.h"
#include <algorithm>

void Pieza::dibuja(const Renderer& renderer, const Vector2D& centro, double ancho, double alto) const {
	
    switch (tipo) {
        case TipoPieza::ARQUERO: renderer.dibujaSprite(arquero.graf, centro, ancho, alto); break;
        case TipoPieza::BANSHEE: renderer.dibujaSprite(banshee.graf, centro, ancho, alto); break;
        case TipoPieza::BASILISCO: renderer.dibujaSprite(basilisco.graf, centro, ancho, alto); break;
		case TipoPieza::CABALLERO: renderer.dibujaSprite(caballero.graf, centro, ancho, alto); break;
		case TipoPieza::CAMBIAFORMA: renderer.dibujaSprite(cambiaforma.graf, centro, ancho, alto); break;
		case TipoPieza::DJINNI: renderer.dibujaSprite(djinni.graf, centro, ancho, alto); break;
		case TipoPieza::DRAGON: renderer.dibujaSprite(dragon.graf, centro, ancho, alto); break;
		case TipoPieza::DUENDE: renderer.dibujaSprite(duende.graf, centro, ancho, alto); break;
		case TipoPieza::FENIX: renderer.dibujaSprite(fenix.graf, centro, ancho, alto); break;
		case TipoPieza::GOLEM: renderer.dibujaSprite(golem.graf, centro, ancho, alto); break;
		case TipoPieza::HECHICERO: renderer.dibujaSprite(hechicero.graf, centro, ancho, alto); break;
		case TipoPieza::MAGO: renderer.dibujaSprite(mago.graf, centro, ancho, alto); break; 
		case TipoPieza::MANTICORA: renderer.dibujaSprite(manticora.graf, centro, ancho, alto); break;
		case TipoPieza::TROL: renderer.dibujaSprite(trol.graf, centro, ancho, alto); break;
		case TipoPieza::UNICORNIO: renderer.dibujaSprite(unicornio.graf, centro, ancho, alto); break;
		case TipoPieza::VALQUIRIA: renderer.dibujaSprite(valquiria.graf, centro, ancho, alto); break;
    }

	double escalaStatus = 0.6;

    //status
    if (!enArena){
        if (mojada) renderer.dibujaSprite(status_mojada.graf, centro, ancho * escalaStatus, alto * escalaStatus);
        if (encarcelada) renderer.dibujaSprite(status_encarcelada.graf, centro, ancho * escalaStatus, alto * escalaStatus);
		if (protegidoContraHechizos) renderer.dibujaSprite(status_proteccion.graf, centro, ancho * escalaStatus, alto * escalaStatus);
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