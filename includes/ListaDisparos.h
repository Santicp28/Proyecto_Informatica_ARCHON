#pragma once
#include <vector>
#include "Pieza.h"
#include "Bordes.h"
#include "InteraccionArena.h"
#include "Disparo.h"
#include "Renderer.h"

using std::vector;
class ListaDisparos
{
	vector<Disparo*> lista;
public:
	inline int size() const { return static_cast<int>(lista.size()); }
	void agregar(Disparo* d) { lista.push_back(d); }
	void dibuja(const Renderer& renderer) const { for (auto d : lista)d->dibuja(renderer); }
	void mueve(double t) { for (auto d : lista)d->mueve(t); }

	void destruir_contenido();
	void eliminar(int index);
	void eliminar(Disparo* d);
	Disparo* operator[](int index);
	//void colision(const Barrera& b) { for (auto d : lista) InteraccionArena::colision(*d, b); }

	//void colision(const Pieza& p) { for (auto d : lista) InteraccionArena::colision(*d, p); }
	void colision(const Bordes& b);
	auto begin() const { return lista.begin(); }
	auto end()   const { return lista.end(); }
	~ListaDisparos() { destruir_contenido(); }
	
};

