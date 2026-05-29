#include "Hechizos.h"


//hechizos sin casilla
void Hechizos::cambiarCiclo(CicloLuz_A_Oscuridad& ciclo) { ciclo.valor = !ciclo.valor; } //para cambiar el ciclo de turno


//hechizos de 1 casilla
void Hechizos::curar(Pieza& p) { if(!p.estaProtegidoContraHechizos()) p.curar(9999.9); }
void Hechizos::encarcelar(Pieza& p) {
	if (!p.estaProtegidoContraHechizos()) p.setEncarcelada(true);
}

void Hechizos::vasoDeAgua(Pieza& p) {
	if (!p.estaProtegidoContraHechizos()){
		p.setAtaque(p.getAtaque() * 1.5); //una bola de papel mojada hace más daño que una seca
		p.setVelocidad(p.getVelocidad() * 0.7); //el agua hace que la bola se mueva más lenta
		p.setDefensa(p.getDefensa() * 0.5); //el agua hace que el papel se rompa más fácilmente
		p.setCadencia(p.getCadencia() * 0.7); //tengo que mojarla y luego tirarla por lo que tardo más
		p.setVidaActual(p.getVidaActual() * 0.5); //el agua daña al papel
		p.setVelocidadAtaque(p.getVelocidadAtaque() * 1.4); //una bola de papel mojado en el aire se mueve más rápido que uba seca
		p.setMojada(true); //para mostrar en sprite y en arena añadir un posible knock back a la otra pieza
	}	
}

//hechizos de 2 casilla
void Hechizos::tp(const PosicionMatriz& origen, const PosicionMatriz& destino, ListaPiezas& lista) { 
	Pieza* p = lista.getPiezaEnPosicion(origen);
	if (!p->estaProtegidoContraHechizos()) lista.moverDeCasilla(origen, destino); 
}
void Hechizos::intercambiar(const PosicionMatriz& origen, const PosicionMatriz& destino, ListaPiezas& lista) {
	PosicionMatriz posicionPivote = { -1, -1 }; 

	Pieza* p1 = lista.getPiezaEnPosicion(origen);
	Pieza* p2 = lista.getPiezaEnPosicion(destino);

	if (!(p1->estaProtegidoContraHechizos() || p2->estaProtegidoContraHechizos())) 
	lista.moverDeCasilla(origen, posicionPivote);
	lista.moverDeCasilla(destino, origen);
	lista.moverDeCasilla(posicionPivote, destino);
}





