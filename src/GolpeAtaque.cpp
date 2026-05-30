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
    const Vector2D& dir) const
{
    double t = anguloGolpe / ANGULO_MAX;

    Vector2D dirHorizontal = (dir.x < 0) ? Vector2D{ -1.0, 0.0 } : Vector2D{ 1.0, 0.0 };
    Vector2D arriba{ 0.0, -1.0 };

    Vector2D dirEspada = (dirHorizontal * (1.0 - t) + arriba * t).unitario();
    Vector2D punta = posJugador + dirEspada * longitud;
    Vector2D centroEspada = posJugador + dirEspada * (longitud * 0.5);

    if (sprite) {
        double angulo = std::atan2(dirEspada.y, dirEspada.x) * (180.0 / Config::PI) + 90.0;
        renderer.dibujaSpriteRotado(sprite, posJugador, longitud*0.35, longitud, angulo);
    }
    else {
        renderer.dibujaLinea(posJugador, punta, { 1.0f, 1.0f, 0.0f });
    }
}