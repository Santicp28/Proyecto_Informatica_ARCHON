#pragma once
#include "Vector2D.h"
#include "Renderer.h"

class GolpeAtaque
{
	double anguloGolpe = 45.0;
	double longitud = 80.0;
	unique_ptr<ETSIDI::Sprite> sprite;

  
public:
    const double ANGULO_MIN = 0.0;
    const double ANGULO_MAX = 45.0;
    const double VELOCIDAD_GOLPE = 300.0;
    GolpeAtaque(const unique_ptr<ETSIDI::Sprite>& spr=nullptr, double longitud_ = 80.0);

    void actualizar(bool atacando, double dt);
    bool colisiona(const Vector2D& posJugador, const Vector2D& dir,
    const Vector2D& posEnemigo, double radioEnemigo) const;
    void dibuja(const Renderer& renderer, const Vector2D& posJugador,
    const Vector2D& dir) const;
    double getAngulo() const { return anguloGolpe; };

private:
    Vector2D getPunta(const Vector2D& posJugador, const Vector2D& dir) const;
};

