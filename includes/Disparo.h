#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "Renderer.h"

class InteraccionArena;
class Disparo :public ObjetoMovil
{
protected:
	Vector2D origen_{};
public:
	Disparo() = default;

	Disparo(const Vector2D& pos, const Vector2D& vel, double sizeradio = 0.25): ObjetoMovil(pos, vel, {}, sizeradio), origen_(pos) {}
	
	const Vector2D& Origen() const { return origen_; }
	
	virtual void dibuja(const Renderer& renderer)const;
	friend class InteraccionArena;
};


