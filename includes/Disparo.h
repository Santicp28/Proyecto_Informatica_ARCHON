#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "Renderer.h"

class InteraccionArena;
class Pieza;
class Disparo :public ObjetoMovil
{
protected:
	Vector2D origen_{};
	const char* sprite = nullptr;
	const Pieza* propietario = nullptr;
public:

	Disparo() = default;

	Disparo(const Vector2D& pos, const Vector2D& vel,const char*spr,const Pieza* prop, double sizeradio = 50.0): 
		ObjetoMovil(pos, vel, {}, sizeradio), origen_(pos), sprite(spr),propietario(prop) {}
	
	const Vector2D& Origen() const { return origen_; }
	const Pieza* getPropietario() const { return propietario; }
	
	virtual void dibuja(const Renderer& renderer)const;
	friend class InteraccionArena;
};


