#pragma once
#include <vector>
#include "Obstaculo.h"
#include "Renderer.h"
class ListaObstaculos {
        std::vector<Obstaculo> lista;
    public:
        void agregar(const Vector2D& pos, const Vector2D& sz, ETSIDI::Sprite spr) {
            lista.emplace_back(pos, sz, spr);
        }
      
        void limpiar() { lista.clear(); }
        int  size() const { return (int)lista.size(); }

        void dibuja(const Renderer& renderer) const {
            for (const auto& o : lista) o.dibuja(renderer);
        }

        const Obstaculo& operator[](int i) const { return lista[i]; }
        auto begin() const { return lista.begin(); }
        auto end()   const { return lista.end(); }
};
