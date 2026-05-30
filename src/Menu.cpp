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


void Menu::dibuja( Grafmenu& grafmenu, const Renderer& renderer)const
{
    renderer.dibujaColorFondo(colorFondo);
    renderer.dibujaCuadrado(grafmenu.sprite, centro ,colorFondo, Config::sizeMundo);
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

void Menu::mueve(float dt)
{

}

MenuAccion Menu::tecla(unsigned char key)
{
    if (key == 'w')
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
        
    if (key == 's')
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
        if(esHechizo(acciones[seleccionado]))
			botones[seleccionado].desactivarBoton(); //desactivamos el hechizo para que no se pueda volver a usar
        return acciones[seleccionado];
    }
    return MenuAccion::NINGUNA;
}

bool Menu::esHechizo(MenuAccion accion)
{
    switch (accion)
    {
    case MenuAccion::TP:
    case MenuAccion::CURAR:
    case MenuAccion::CAMBIAR_TIEMPO:
    case MenuAccion::INTERCAMBIAR:
    case MenuAccion::ENCARCELAR:
    case MenuAccion::TIJERAS:
        return true;

    default:
        return false;
    }
}

void Menu::teclaEspecial(int key)
{
}