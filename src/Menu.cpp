#include "Menu.h"

Menu::Menu(const std::vector<std::string>& textos, const Vector2D& sMenu, const Vector2D& c, const string& titu):
    sizeMenu(sMenu),titulo(titu), centro(c)
{
    for (const auto& texto : textos)
        botones.emplace_back(texto);//cuando pasas argumentos del constructor:emplace_back (llama constructor sin hacer copia temporal)
}
void Menu::inicializa()
{
    for ( auto& boton : botones)
        boton.inicializa();
    seleccionado = 0;
    botones[seleccionado].cambiarEstado();

}


void Menu::dibuja(const Renderer& renderer)const
{
    renderer.dibujaColorFondo(colorFondo);
    const Vector2D sizeBotones{ calcularSizeBotones() };
    for (int i = 0; i < botones.size(); i++) {
        botones[i].dibuja(renderer,calcularPosicionBotones(i), sizeBotones);
    }
}

void Menu::mueve(float dt)
{

}

MenuAccion Menu::tecla(unsigned char key)
{
    if (key == 'w')
    {
        if (seleccionado == 0) {
            botones[seleccionado].cambiarEstado();
            seleccionado = botones.size() - 1;
            botones[seleccionado].cambiarEstado();
        }
        else {
            botones[seleccionado].cambiarEstado();
            seleccionado = seleccionado - 1;
            botones[seleccionado].cambiarEstado();
        }
    }
        
    if (key == 's')
    {
        if (seleccionado == botones.size() - 1) {
            botones[seleccionado].cambiarEstado();
            seleccionado = 0;
            botones[seleccionado].cambiarEstado();
        }
        else {
            botones[seleccionado].cambiarEstado();
            seleccionado = seleccionado + 1;
            botones[seleccionado].cambiarEstado();
        }
    }
    if (key == ' ')
    {
        switch (seleccionado)
        {
        case 0: return MenuAccion::JUGAR;
        case 1: return MenuAccion::OPCIONES;
        case 2: return MenuAccion::SALIR;
        }
    }
    return MenuAccion::NINGUNA;
}

void Menu::teclaEspecial(int key)
{
}