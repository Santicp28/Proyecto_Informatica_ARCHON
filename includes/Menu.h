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
    string titulo{ "ARCHON" };

public:
    Menu(const std::vector<std::string>& textos)
    {
        for (const auto& texto : textos)
            botones.emplace_back(texto);//cuando pasas argumentos del constructor:emplace_back (llama constructor sin hacer copia temporal). Cuando ya tienes el objeto creado:push_back
    }

    void inicializa();
    void dibuja(const Renderer& renderer);
    void mueve(float dt);
  
    MenuAccion tecla(unsigned char key);
    void teclaEspecial(int key);
private:
    Vector2D calcularPosicionBotones(int ordenBoton)const { return { Config::sizeMundo.x * 0.5, (ordenBoton + 1) * Config::sizeMundo.y / (botones.size() + 1.0) }; } //calcula la separecion entre botones Config::sizeMundo.y / (botones.size() + 1.0)
    Vector2D calcularSizeBotones()const { return{ Config::sizeMundo.x * 0.4, (Config::sizeMundo.x * 0.4) * 0.2 }; }

};