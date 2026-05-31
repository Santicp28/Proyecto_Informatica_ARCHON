#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "Renderer.h"
#include "ContenedorSprites.h"

class InteraccionArena;
class Pieza;
class Disparo :public ObjetoMovil
{
protected:
	Vector2D origen_{};
	const std::unique_ptr<Sprite> sprite = nullptr;
	const Pieza* propietario = nullptr;
public:

	Disparo() = default;

	Disparo(const Vector2D& pos, const Vector2D& vel,const std::unique_ptr<Sprite>& spr,const Pieza* prop, double sizeradio = 20.0): 
		ObjetoMovil(pos, vel, {}, sizeradio), origen_(pos), sprite(spr.get()),propietario(prop) {}
	
	const Vector2D& Origen() const { return origen_; }
	const Pieza* getPropietario() const { return propietario; }
	
	virtual void dibuja(const Renderer& renderer) const;
	friend class InteraccionArena;
};


