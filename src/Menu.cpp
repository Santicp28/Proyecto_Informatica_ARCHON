#include "Menu.h"

void Menu::inicializa()
{
    seleccionado = 0;
    botones[seleccionado].cambiarEstado();
}


void Menu::dibuja(const Renderer& renderer)
{
    renderer.dibujaColorFondo(colorFondo);
    Vector2D sizeBotones{ calcularSizeBotones() };
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