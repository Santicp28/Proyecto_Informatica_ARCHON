#include "Arena.h"

void Arena::inicializa(Pieza* p1, Pieza* p2)
{
	if (p1->getBando() == Bando::LUZ) {
		jugador1 = p1;
		jugador2 = p2;
	}
	else {
		jugador1 = p2;
		jugador2 = p1;
	}
    jugador1->setPosicionArena(posicionInicialJugador1);
    jugador2->setPosicionArena(posicionInicialJugador2);

    combateTerminado = false;
    ganadorBando = 0;
   
}
void Arena::tecla(unsigned char key) {
    teclas[key] = true;
	jugador1->atacar = teclas[' '];
	jugador2->atacar = teclas[13];

	Vector2D vel{ 0, 0 };
	double speed = jugador1->getVelocidad();
	if (teclas['w'] || teclas['W']) vel.y = -speed;
	if (teclas['s'] || teclas['S']) vel.y = speed;
	if (teclas['a'] || teclas['A']) vel.x = -speed;
	if (teclas['d'] || teclas['D']) vel.x = speed;
	if (vel.modulo() > 0)
		vel = vel.unitario() * speed;
	jugador1->velocidad(vel);
}
void Arena::teclaUP(unsigned char key) { 
    teclas[key] = false;
	jugador1->atacar = teclas[' '];
	jugador2->atacar = teclas[13];
	Vector2D vel(0, 0);
	double speed = jugador1->getVelocidad();
	if (teclas['w'] || teclas['W']) vel.y = -speed;
	if (teclas['s'] || teclas['S']) vel.y = speed;
	if (teclas['a'] || teclas['A']) vel.x = -speed;
	if (teclas['d'] || teclas['D']) vel.x = speed;
	if (vel.modulo() > 0)
		vel = vel.unitario() * speed;
	jugador1->velocidad(vel);
}
void Arena::teclaEspecial(int key) { 
    teclasEspeciales[key] = true; 
	Vector2D vel{ 0, 0 };
	double speed = jugador2->getVelocidad();
	if (teclasEspeciales[GLUT_KEY_UP]) vel.y = -speed;
	if (teclasEspeciales[GLUT_KEY_DOWN]) vel.y = speed;
	if (teclasEspeciales[GLUT_KEY_LEFT]) vel.x = -speed;
	if (teclasEspeciales[GLUT_KEY_RIGHT]) vel.x = speed;
	if (vel.modulo() > 0)
		vel = vel.unitario() * speed;
	jugador2->velocidad(vel);
    

}
void Arena::teclaEspecialUP(int key) { 
    teclasEspeciales[key] = false; 
	Vector2D vel{ 0, 0 };
	double speed = jugador2->getVelocidad();
	if (teclasEspeciales[GLUT_KEY_UP]) vel.y = -speed;
	if (teclasEspeciales[GLUT_KEY_DOWN]) vel.y = speed;
	if (teclasEspeciales[GLUT_KEY_LEFT]) vel.x = -speed;
	if (teclasEspeciales[GLUT_KEY_RIGHT]) vel.x = speed;
	if (vel.modulo() > 0)
		vel = vel.unitario() * speed;
	jugador2->velocidad(vel);
}
void Arena::mueve(float dt)
{
	if (combateTerminado) return;

	jugador1->mueve(dt);
	jugador2->mueve(dt);

	InteraccionArena::colision(*jugador1, bordes);
	InteraccionArena::colision(*jugador2, bordes);
	InteraccionArena::colision(*jugador1, *jugador2);


	listaDisparos.mueve(dt);
	for (int i = listaDisparos.size() - 1; i >= 0; --i) {

		if (InteraccionArena::colision(*listaDisparos[i], bordes)) {
			listaDisparos.eliminar(i);
			continue;
		}
		if (InteraccionArena::colision(*listaDisparos[i], *jugador2) &&
			listaDisparos[i]->getPropietario() != jugador2) {
			jugador2->recibirDanio(jugador1->getAtaque());
			listaDisparos.eliminar(i);
			continue;
		}
		if (InteraccionArena::colision(*listaDisparos[i], *jugador1) &&
			listaDisparos[i]->getPropietario() != jugador1) {
			jugador1->recibirDanio(jugador2->getAtaque());
			listaDisparos.eliminar(i);
			continue;
		}
	}

	if (jugador1->puedeDisparar()) {
		listaDisparos.agregar(new Disparo(
			jugador1->posicion(),
			jugador1->getDireccion() * jugador1->getVelocidadAtaque(),
			jugador1->getSpriteAtaque(),
			jugador1
		));
	}
	if (jugador2->puedeDisparar()) {
		listaDisparos.agregar(new Disparo(
			jugador2->posicion(),
			jugador2->getDireccion() * jugador2->getVelocidadAtaque(),
			jugador2->getSpriteAtaque(),
			jugador2
		));
	}

}

void Arena::dibuja(const Renderer& renderer) const
{
    bordes.dibuja(renderer);
    listaDisparos.dibuja(renderer);
	if (jugador1) jugador1->dibuja(renderer, jugador1->posicion(), 175.0, 175.0);
	if (jugador2) jugador2->dibuja(renderer, jugador2->posicion(), 175.0, 175.0);
}

Pieza* Arena::getGanador() const
{
    if (!combateTerminado) return nullptr;
    if (ganadorBando == 1) return jugador1;
    if (ganadorBando == 2) return jugador2;
    return nullptr; // empate
}
