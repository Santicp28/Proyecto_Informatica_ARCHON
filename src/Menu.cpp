#include "Menu.h"

Menu::Menu(const vector<string>& textos, const vector<MenuAccion>& acc, const Vector2D& sMenu, const Vector2D& c, const string& titu, const Color& colorTit):
    sizeMenu(sMenu),titulo(titu), centro(c), colorTitulo(colorTit), acciones(acc)
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
    renderer.dibujaTexto(titulo, calcularPosicionBotones(-1), { 0.0f,0.0f,0.0f }, sizeBotones.y * 0.8, AlineacionTexto::CENTRADO);
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
    if (key == ' ') {

        return acciones[seleccionado];
    }
    return MenuAccion::NINGUNA;
}

void Menu::teclaEspecial(int key)
{
}

Vector2D Menu::calcularSizeBotones() const
{
    return{ sizeMenu.x * 0.6, sizeMenu.y / (botones.size() + 1.0) * 0.6 };
}