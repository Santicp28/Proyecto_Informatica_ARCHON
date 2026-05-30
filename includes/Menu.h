#pragma once
#include"Renderer.h"
#include "Boton.h"
#include "Config.h"
#include "ContenedorSprites.h"
#include "Tipos.h"
#include<string>
#include <vector>
using std::vector, std::string;

class Menu {
    vector<Boton> botones;
    vector<MenuAccion> acciones;
    Color colorFondo{ 0.1f, 0.1f, 0.4f };
	Color colorTitulo{ 0.0f, 0.0f, 0.0f };
    unsigned int seleccionado{ 0 };
    string titulo;
    Vector2D sizeMenu;
    Vector2D centro;

public:
    Menu(const vector<string>& textos,const vector<MenuAccion>& acc, const Vector2D& sMenu, const Vector2D& c, const string& titu, const Color& colorTit);

    void inicializa();
    void dibuja(const Renderer& renderer, const ContenedorSprites& contenedorSprites)const;
    void mueve(float dt);
  
    MenuAccion tecla(unsigned char key);
    bool esHechizo(MenuAccion accion);
    void teclaEspecial(int key);
private:
    Vector2D calcularPosicionBotones(int ordenBoton)const { return { sizeMenu.x * 0.5, (ordenBoton + 2) * sizeMenu.y / (botones.size() + 2.0) }; } //calcula la separecion entre botones Config::sizeMundo.y / (botones.size() + 1.0)
    Vector2D calcularSizeBotones()const{ return{ sizeMenu.x * 0.6, sizeMenu.y / (botones.size() + 1.0) * 0.6 }; }

};