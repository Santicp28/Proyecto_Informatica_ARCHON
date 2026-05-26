#pragma once
#include"Renderer.h"
#include "Boton.h"
#include "Config.h"
#include "Tipos.h"
#include<string>
#include <vector>
using std::vector, std::string;

class Menu {
    vector<Boton> botones;
    Color colorFondo{ 0.1f, 0.1f, 0.4f };
    unsigned int seleccionado{ 0 };
    string titulo;
    Vector2D sizeMenu;
    Vector2D centro;

public:
    Menu(const std::vector<std::string>& textos, const Vector2D& sMenu, const Vector2D& c, const string& titu);

    void inicializa();
    void dibuja(const Renderer& renderer)const;
    void mueve(float dt);
  
    MenuAccion tecla(unsigned char key);
    void teclaEspecial(int key);
private:
    Vector2D calcularPosicionBotones(int ordenBoton)const { return { sizeMenu.x * 0.5, (ordenBoton + 1) * sizeMenu.y / (botones.size() + 1.0) }; } //calcula la separecion entre botones Config::sizeMundo.y / (botones.size() + 1.0)
    Vector2D calcularSizeBotones()const { return{ sizeMenu.x * 0.5, (sizeMenu.x * 0.4) * 0.2 }; }

};