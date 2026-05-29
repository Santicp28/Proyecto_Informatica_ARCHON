#include "Arena.h"

bool Arena::esPosicionReservada(const Vector2D& pos, float margen) const
{
    auto cerca = [&](const Vector2D& ref) {
        float dx = pos.x - ref.x;
        float dy = pos.y - ref.y;
        return (dx * dx + dy * dy) < (margen * margen);
        };

    return cerca(centro)
        || cerca(posicionInicialJugador1)
        || cerca(posicionInicialJugador2);
}

void Arena::generaObstaculos(int cantidad, unsigned int semilla)
{
    listaObstaculos.limpiar();
    std::srand(semilla == 0 ? static_cast<unsigned>(std::time(nullptr)) : semilla);

    const float margenBorde = size.x * 0.08f;
    const float xMin = margenBorde;
    const float xMax = size.x - margenBorde;
    const float yMin = margenBorde;
    const float yMax = size.y - margenBorde;
    const Vector2D obsSize{ size.x * 0.04f, size.y * 0.04f };
    const float margenReservado = size.x * 0.15f;

    const int maxIntentos = 20;
    int colocados = 0;
    int intentos = 0;

    while (colocados < cantidad && intentos < maxIntentos)
    {
        ++intentos;

        float rx = xMin + static_cast<float>(std::rand()) / RAND_MAX * (xMax - xMin);
        float ry = yMin + static_cast<float>(std::rand()) / RAND_MAX * (yMax - yMin);
        Vector2D candidato{ rx, ry };

        if (esPosicionReservada(candidato, margenReservado))
            continue;

        bool solapa = false;
        for (const auto& obs : listaObstaculos)
        {
            float dx = candidato.x - obs.posicion.x;
            float dy = candidato.y - obs.posicion.y;
            if (std::abs(dx) < obsSize.x * 2 && std::abs(dy) < obsSize.y * 2)
            {
                solapa = true;
                break;
            }
        }
        if (solapa) continue;

		listaObstaculos.agregar( candidato, obsSize, arbolverde.sprite );
        ++colocados;
    }
}

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
   
    generaObstaculos(8);
}
void Arena::tecla(unsigned char key) {
    teclas[key] = true;
	jugador1->atacar = teclas[' '];
	jugador2->atacar = teclas[13];

	Vector2D 	vel{ 0.0, 0.0 };

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
	Vector2D vel{ 0.0, 0.0 };
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
	Vector2D vel{ 0.0, 0.0 };
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
	//---------obstaculos---------
	for (const auto& obs : listaObstaculos) {
		InteraccionArena::colision(*jugador1, obs);
		InteraccionArena::colision(*jugador2, obs);
	}
	//---------disparos---------
	listaDisparos.mueve(dt);
	for (int i = listaDisparos.size() - 1; i >= 0; --i) {

		if (InteraccionArena::colision(*listaDisparos[i], bordes)) {
			listaDisparos.eliminar(i);
			continue;
		}
		bool destruido = false;
		for (const auto& obs : listaObstaculos) {
			if (InteraccionArena::colision(*listaDisparos[i], obs)) {
				listaDisparos.eliminar(i);
				destruido = true;
				break;
			}
		}
		if (destruido) continue;
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

	//--------vida----------
	if (jugador1->getVidaActual() <= 0) {
		combateTerminado = true;
		ganadorBando = 2;
	}
	else if (jugador2->getVidaActual() <= 0) {
		combateTerminado = true;
		ganadorBando = 1;
	}

	//-------ataque cuerpo a cuerpo ------
	if (jugador1->esAtaqueMelee()) jugador1->actualizarGolpe(dt);
	if (jugador2->esAtaqueMelee()) jugador2->actualizarGolpe(dt);

	/*if (jugador1->esAtaqueMelee() && jugador1->golpeActivo() && !jugador1->golpeYaConecto) {
		if (InteraccionArena::colision(jugador1->getGolpe(), jugador1->posicion(),
			jugador1->getDireccion(), *jugador2)) {
			jugador2->recibirDanio(jugador1->getAtaque());
			jugador1->golpeYaConecto = true;
		}
	}*/

	if (jugador1->esAtaqueMelee() && jugador1->golpeActivo()) {
		printf("[MELEE J1] golpeActivo=true, golpeYaConecto=%d\n", jugador1->golpeYaConecto);
		if (InteraccionArena::colision(jugador1->getGolpe(), jugador1->posicion(),
			jugador1->getDireccion(), *jugador2)) {
			printf("[MELEE J1] COLISION DETECTADA\n");
			if (!jugador1->golpeYaConecto) {
				jugador2->recibirDanio(jugador1->getAtaque());
				jugador1->golpeYaConecto = true;
				printf("[MELEE J1] DANIO APLICADO\n");
			}
		}
	}






	if (jugador2->esAtaqueMelee() && jugador2->golpeActivo() && !jugador2->golpeYaConecto) {
		if (InteraccionArena::colision(jugador2->getGolpe(), jugador2->posicion(),
			jugador2->getDireccion(), *jugador1)) {
			jugador1->recibirDanio(jugador2->getAtaque());
			jugador2->golpeYaConecto = true;
		}
	}
}

void Arena::dibuja(const Renderer& renderer) const
{
	renderer.dibujaSprite(pizarra.sprite, centro, size.x, size.y);
    bordes.dibuja(renderer);
    

	listaObstaculos.dibuja(renderer);
	listaDisparos.dibuja(renderer);
	if (jugador1) jugador1->dibuja(renderer, jugador1->posicion(), 175.0, 175.0);
	if (jugador2) jugador2->dibuja(renderer, jugador2->posicion(), 175.0, 175.0);
	if (jugador1 && jugador1->esAtaqueMelee())
		jugador1->getGolpe().dibuja(renderer, jugador1->posicion(), jugador1->getDireccion());
	if (jugador2 && jugador2->esAtaqueMelee())
		jugador2->getGolpe().dibuja(renderer, jugador2->posicion(), jugador2->getDireccion());

}

Pieza* Arena::getGanador() const
{
    if (!combateTerminado) return nullptr;
    if (ganadorBando == 1) return jugador1;
    if (ganadorBando == 2) return jugador2;
    return nullptr; // empate
}
