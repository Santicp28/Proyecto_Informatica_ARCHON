#include "Menu.h"
#include "freeglut.h"

void Menu::inicializa()
{
    seleccionado = 0;
}


void Menu::dibuja(const Renderer& renderer)
{
    renderer.dibujaColorFondo(colorFondo);

    for (int i = 0; i < botones.size(); i++) {

        botones[i].dibuja();
    }
}

void Menu::mueve(float dt)
{
    for (int i = 0; i < botones.size(); i++)
    {
        if (i == seleccionado)
            botones[i].setParametros(true);
        else
            botones[i].setParametros(false);
    }
}


void Menu::tecla(unsigned char key)
{
    if (key == 'w' || key == 'J')
        if (seleccionado == 0)
            seleccionado = botones.size() - 1;
        else
            seleccionado = seleccionado - 1;

    if (key == 's' || key == 'R')
        if (seleccionado == botones.size()-1)
            seleccionado = 0;
        else
            seleccionado = seleccionado +1;

    if (key == ' ')
        //confirmar
}

void Menu::teclaEspecial(int key)
{
}