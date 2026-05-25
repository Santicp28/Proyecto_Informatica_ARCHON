//#pragma once
//#include <vector>
//#include "InteraccionArena.h"
//#include "disparo.h"
//using std::vector;
//class ListaDisparos
//{
//	vector<Disparo*> lista;
//public:
//	inline int size() const { return static_cast<int>(lista.size()); }
//	void agregar(Disparo* d) { lista.push_back(d); }
//	void dibuja() const { for (auto d : lista)d->dibuja(); }
//	void mueve(double t) { for (auto d : lista)d->mueve(t); }
//
//	void destruir_contenido();
//	void eliminar(int index);
//	void eliminar(Disparo* d);
//	Disparo* operator[](int index);
//
//	void colision(const Caja& c) { for (auto d : lista)Interaccion::colision(*d, c); }
//
//	void colision(const Pared& p) { for (auto d : lista)Interaccion::colision(*d, p); }
//
//	auto begin() const { return lista.begin(); }
//	auto end()   const { return lista.end(); }
//
//};
//
