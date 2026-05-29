#include "GolpeAtaque.h"
#include <algorithm>
#include "Config.h"
using std::clamp;
GolpeAtaque::GolpeAtaque(const char* spr, double longitud_)
    : sprite(spr), longitud(longitud_)
{
}
void GolpeAtaque::actualizar(bool atacando, double dt)
{
    if (atacando)
        anguloGolpe -= VELOCIDAD_GOLPE * dt;  // mueve espada hasta 0º
    else
        anguloGolpe += VELOCIDAD_GOLPE * dt;  // vuelve a 45° cuando sueltas espacio
    anguloGolpe = clamp(anguloGolpe, ANGULO_MIN, ANGULO_MAX);
}

bool GolpeAtaque::colisiona(const Vector2D& posJugador, const Vector2D& dir,
    const Vector2D& posEnemigo, double radioEnemigo) const
{
    if (anguloGolpe > 10.0) return false;  // solo detecta cuando está casi extendido
    Vector2D punta = getPunta(posJugador, dir);
    return (punta - posEnemigo).modulo() < (20.0 + radioEnemigo);
}

Vector2D GolpeAtaque::getPunta(const Vector2D& posJugador, const Vector2D& dir) const
{
    double rad = anguloGolpe * (Config::PI / 180.0);
    double dist = longitud * std::cos(rad);
    return posJugador + dir * dist;
}

void GolpeAtaque::dibuja(const Renderer& renderer, const Vector2D& posJugador,
    const Vector2D& dir) const {
    double t = anguloGolpe / ANGULO_MAX; // posicion inicial es 45º y final es en 0º

    Vector2D dirHorizontal = (dir.x < 0) ? Vector2D{ -1.0, 0.0 } : Vector2D{ 1.0, 0.0 };
    Vector2D arriba{ 0.0, -1.0 };

    // hace el arco desde 45º a 0º
    Vector2D dirEspada = (dirHorizontal * (1.0 - t) + arriba * t).unitario();
    Vector2D punta = posJugador + dirEspada * longitud;

    renderer.dibujaLinea(posJugador, punta, { 1.0f, 1.0f, 0.0f });

}