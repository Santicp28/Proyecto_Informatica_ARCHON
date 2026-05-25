//#pragma once
//#include "Vector2D.h"
//class ObjetoMovil
//{
//protected:
//	Vector2D posicion_;
//	Vector2D velocidad_;
//	Vector2D aceleracion_;
//
//public:
//	ObjetoMovil(Vector2D pos = {}, Vector2D vel = {}, Vector2D acel = {}) :
//		posicion_{ pos }, velocidad_{ vel }, aceleracion_{ acel } {
//	}
//
//	virtual ~ObjetoMovil() = default;
//
//	virtual void mueve(double t)
//	{
//		posicion_ = posicion_ + velocidad_ * t + 0.5 * aceleracion_ * t * t;
//		velocidad_ = velocidad_ + aceleracion_ * t;
//	}
//
//	// lectura
//	const Vector2D& posicion() const { return posicion_; }
//	const Vector2D& velocidad() const { return velocidad_; }
//
//	// escritura
//	void posicion(const Vector2D& p) { posicion_ = p; }
//	void velocidad(const Vector2D& v) { velocidad_ = v; }
//
//};
//
// 