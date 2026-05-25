//#include "freeglut.h"
//#include "disparo.h"
//#include "ObjetoMovil.h"
//
////crea un proyectil en la dirección actual del atacante
//void Disparo::crearProyectil(EstadoCombate& atacante)
//{
//    Proyectil p;
//    p.posicion = atacante.posicion;
//    p.velocidad = atacante.direccion * VELOCIDAD_PROYECTIL;
//    p.danio = DANIO_PROYECTIL;
//    p.propietario = &atacante;
//
//    proyectiles.push_back(p);
//
//    atacante.cooldown = CADENCIA_PROYECTIL;
//    atacante.atacar = false;
//}
//
////mueve todos los proyectiles y comprueba colisiones
//void Disparo::actualizarProyectiles(float dt)
//{
//    for (auto& p : proyectiles)
//        p.posicion = p.posicion + p.velocidad * dt;
//
//    comprobarColisionProyectiles();
//}
//
////elimina proyectiles que impactan o salen de la arena
//void Disparo::comprobarColisionProyectiles()
//{
//    for (auto it = proyectiles.begin(); it != proyectiles.end();)
//    {
//        // el objetivo es siempre el enemigo del propietario
//        EstadoCombate* objetivo = (it->propietario == &jugador1) ? &jugador2 : &jugador1;
//
//        bool impacto = InteraccionArena::colisionMelee(it->posicion, it->radio, objetivo->posicion, objetivo->radio);
//
//        bool fueraArena =
//            it->posicion.x < BordesArena::X_MIN ||
//            it->posicion.x > BordesArena::X_MAX ||
//            it->posicion.y < BordesArena::Y_MIN ||
//            it->posicion.y > BordesArena::Y_MAX;
//
//        if (impacto)
//        {
//            objetivo->vida -= it->danio;
//            if (objetivo->vida < 0) objetivo->vida = 0;
//            it = proyectiles.erase(it);
//        }
//        else if (fueraArena)
//        {
//            it = proyectiles.erase(it);
//        }
//        else
//        {
//            ++it;
//        }
//    }
//}
//// dibuja todos los proyectiles activos como círculos rojos 
//void Disparo::dibujarProyectiles() const
//{
//    for (const auto& p : proyectiles)
//    {
//        glPushMatrix();
//        glTranslatef((float)p.posicion.x, (float)p.posicion.y, 0);
//        glColor3f(1.0f, 0.0f, 0.0f);
//
//        glBegin(GL_POLYGON);
//        for (int i = 0; i < 24; i++)
//        {
//            float a = 2.0f * 3.14159f * i / 24.0f;
//            glVertex2f(cos(a) * p.radio, sin(a) * p.radio);
//        }
//        glEnd();
//        glPopMatrix();
//    }
//}