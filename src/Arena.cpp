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
    obstaculos.clear();
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
        for (const auto& obs : obstaculos)
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

        obstaculos.push_back({ candidato, obsSize });
        ++colocados;
    }
}

void Arena::inicializa(Pieza* p1, Pieza* p2)
{
    jugador1 = p1;
    jugador2 = p2;
    jugador1->setPosicionArena(posicionInicialJugador1);
    jugador2->setPosicionArena(posicionInicialJugador2);

    combateTerminado = false;
    ganadorBando = 0;
   
    generaObstaculos(8);
}

//void Arena::mueve(float dt)
//
//{
//
//    if (combateTerminado) return;
//
//    //MOVER
//    jugador1.posicion = jugador1.posicion + jugador1.velocidad * dt;
//    jugador2.posicion = jugador2.posicion + jugador2.velocidad * dt;
//
//    //COOLDOWNS
//    jugador1.cooldown -= dt; if (jugador1.cooldown < 0) jugador1.cooldown = 0;
//    jugador2.cooldown -= dt; if (jugador2.cooldown < 0) jugador2.cooldown = 0;
//
//    //COLISIÓN CON BORDES
//    InteraccionArena::colision(p1, bordes);
//    InteraccionArena::colision(p2, bordes);
//
//    bool muereJ1 = jugador1.vida <= 0;
//    bool muereJ2 = jugador2.vida <= 0;
//   
//    if (muereJ1 && muereJ2)
//    {
//        // empate — mueren los dos en el mismo frame
//        combateTerminado = true;
//        ganadorBando = 0;
//    }
//    else if (muereJ1)
//    {
//        combateTerminado = true;
//        ganadorBando = 2;
//    }
//    else if (muereJ2)
//    {
//        combateTerminado = true;
//        ganadorBando = 1;
//    }
//}

void Arena::dibuja(const Renderer& renderer) const
{
   
    bordes.dibuja(renderer);
    renderer.dibujaSprite(fondoarena.sprite, centro, size.x, size.y);


    for (const auto& obs : obstaculos)
        renderer.dibujaSprite(arbolverde.sprite, obs.posicion, obs.size.x, obs.size.y);
}
//
//void Arena::tecla(unsigned char key)
//{
//    if (combateTerminado) return;
//    switch (key)
//    {
//    case 'w':
//    case 'W':
//        jugador1.velocidad.y = VELOCIDAD;
//        break;
//    case 's':
//    case 'S':
//        jugador1.velocidad.y = -VELOCIDAD;
//        break;
//    case 'a':
//    case 'A':
//        jugador1.velocidad.x = -VELOCIDAD;
//        break;
//    case 'd':
//    case 'D':
//        jugador1.velocidad.x = VELOCIDAD;
//        break;
//    
//    case ' ':
//        jugador1.atacar = true;
//        break;
//
//    case 13:  
//        jugador2.atacar = true; 
//        break; //13 es tecla enter
//
//    
//    }
//}
//
//void Arena::teclaUP(unsigned char key)
//{
//    switch (key)
//    {
//
//    case 'w':
//    case 'W':
//    case 's':
//    case 'S':
//        jugador1.velocidad.y = 0;
//        break;
//
//    case 'a':
//    case 'A':
//    case 'd':
//    case 'D':
//        jugador1.velocidad.x = 0;
//        break;
//
//    case ' ':
//        jugador1.atacar = false;
//        break;
//
//    case 13:  
//        jugador2.atacar = false;
//        break; //13 es tecla enter
//    }
//}
//
//
//void Arena::teclaEspecial(int key)
//{
//    if (combateTerminado) return;
//    switch (key)
//    {
//    case GLUT_KEY_UP:
//        jugador2.velocidad.y = VELOCIDAD;
//        break;
//
//    case GLUT_KEY_DOWN:
//        jugador2.velocidad.y = -VELOCIDAD;
//        break;
//
//    case GLUT_KEY_LEFT:
//        jugador2.velocidad.x = -VELOCIDAD;
//        break;
//
//    case GLUT_KEY_RIGHT:
//        jugador2.velocidad.x = VELOCIDAD;
//        break;
//    }
//
//}
//void Arena::teclaEspecialUP(int key)
//{
//    switch (key)
//    {
//
//    case GLUT_KEY_UP:
//    case GLUT_KEY_DOWN:
//        jugador2.velocidad.y = 0;
//         break;
//    case GLUT_KEY_LEFT:
//    case GLUT_KEY_RIGHT:
//         jugador2.velocidad.x = 0;
//         break;
//    }
//}