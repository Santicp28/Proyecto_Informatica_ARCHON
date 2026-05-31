#pragma once
#include"Renderer.h"
#include "Boton.h"
#include "Config.h"
#include "Grafmenu.h"
#include "Grafhechizos.h"
#include "Menu.h"
#include "Tipos.h"
#include<string>
#include <vector>

using std::vector, std::string;

class MenuHechizos : public Menu {
        
public:
    MenuHechizos(const vector<string>& textos,const vector<MenuAccion>& acc, const Vector2D& sMenu, const Vector2D& c, const string& titu, const Color& colorTit) : 
        Menu (textos, acc, sMenu, c, titu, colorTit) {}


    void dibuja(const Renderer& renderer) const override;
    void dibujaSpriteHechizo(MenuAccion accion, const Renderer& renderer, const Vector2D& posicionBoton, const Vector2D& sizeBoton, bool estaSeleccionado) const;
  
    MenuAccion tecla(unsigned char key) override;

    bool esHechizo(MenuAccion accion);
    
    void recolocarSeleccion();

};