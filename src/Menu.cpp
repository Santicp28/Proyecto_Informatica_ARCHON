#include "Menu.h"
#include "Renderer.h"

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


void Menu::dibuja(const Grafmenu& grafmenu, const Renderer& renderer)const
{
    renderer.dibujaColorFondo(colorFondo);
    renderer.dibujaSprite(grafmenu.sprite, centro , Config::sizeMundo.x, Config::sizeMundo.y);
    const Vector2D sizeBotones{ calcularSizeBotones() };
    renderer.dibujaTexto(titulo, calcularPosicionBotones(-1), { 0.0f,0.0f,0.0f }, sizeBotones.y * 0.8, AlineacionTexto::CENTRADO);
    for (int i = 0; i < botones.size(); i++) {
        botones[i].dibuja(renderer,calcularPosicionBotones(i), sizeBotones * 0.5);
    }
}


void Menu::dibuja(const Renderer& renderer) const
{
	renderer.dibujaColorFondo(colorFondo);
	const Vector2D sizeBotones{ calcularSizeBotones() };
	renderer.dibujaTexto(titulo, calcularPosicionBotones(-1), colorTitulo, sizeBotones.y * 0.8, AlineacionTexto::CENTRADO);
	for (int i = 0; i < botones.size(); i++) {
		botones[i].dibuja(renderer, calcularPosicionBotones(i), sizeBotones * 0.5);
	}
}


MenuAccion Menu::tecla(unsigned char key)
{
    if (key == 'w' || key == 'W')
    {
        botones[seleccionado].cambiarEstado();
        do {
            if (seleccionado == 0) 
                seleccionado = botones.size() - 1;
            else 
                seleccionado--;
        } while (botones[seleccionado].estaDesactivo());
        botones[seleccionado].cambiarEstado();
    }
        
    if (key == 's' || key == 'S')
    {
        botones[seleccionado].cambiarEstado();
        do {
            if (seleccionado == botones.size() - 1) {
                seleccionado = 0;
            }
            else {
                seleccionado++;
            }
        } while (botones[seleccionado].estaDesactivo());
        botones[seleccionado].cambiarEstado();
    }
    if (key == ' ') 
    {
        return acciones[seleccionado];
    }
    return MenuAccion::NINGUNA;
}
