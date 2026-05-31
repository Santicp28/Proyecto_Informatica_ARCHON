#include "MenuHechizos.h"
#include "Renderer.h"

    
MenuAccion MenuHechizos::tecla(unsigned char key) 
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
        if(esHechizo(acciones[seleccionado]))
			botones[seleccionado].desactivarBoton(); //desactivamos el hechizo para que no se pueda volver a usar
        return acciones[seleccionado];
    }
    return MenuAccion::NINGUNA;
}

void MenuHechizos::dibuja(const Renderer& renderer) const
{
    renderer.dibujaColorFondo(colorFondo);
    const Vector2D sizeBotones{ calcularSizeBotones() };
    renderer.dibujaTexto(titulo, calcularPosicionBotones(-1), colorTitulo, sizeBotones.y * 0.8, AlineacionTexto::CENTRADO);

    for (int i = 0; i < botones.size(); i++) {
        botones[i].dibuja(renderer, calcularPosicionBotones(i), sizeBotones * 0.5);

        dibujaSpriteHechizo(acciones[i], renderer, calcularPosicionBotones(i), sizeBotones * 0.5, i == seleccionado);
    }
}

void MenuHechizos::dibujaSpriteHechizo(MenuAccion accion, const Renderer& renderer, const Vector2D& posicionBoton, const Vector2D& sizeBoton, bool estaSeleccionado) const
{
    double ladoSprite = sizeBoton.y ;

    if (estaSeleccionado) ladoSprite = sizeBoton.y * 1.4;

    Vector2D posicionSprite{posicionBoton.x + sizeBoton.x * 1.2, posicionBoton.y};

    switch (accion)
    {
    case MenuAccion::TP:
        renderer.dibujaSprite(teletransportar.graf, posicionSprite, ladoSprite, ladoSprite);
        break;

    case MenuAccion::CURAR:
        renderer.dibujaSprite(curar.graf, posicionSprite, ladoSprite, ladoSprite);
        break;

    case MenuAccion::CAMBIAR_TIEMPO:
        renderer.dibujaSprite(tiempo.graf, posicionSprite, ladoSprite, ladoSprite);
        break;

    case MenuAccion::INTERCAMBIAR:
        renderer.dibujaSprite(intercambio.graf, posicionSprite, ladoSprite, ladoSprite);
        break;

    case MenuAccion::ENCARCELAR:
        renderer.dibujaSprite(status_encarcelada.graf, posicionSprite, ladoSprite, ladoSprite);
        break;

    case MenuAccion::VASO_DE_AGUA:
        renderer.dibujaSprite(vaso_de_agua.graf, posicionSprite, ladoSprite, ladoSprite);
        break;

    default:
        break;
    }
}

bool MenuHechizos::esHechizo(MenuAccion accion)
{
    switch (accion)
    {
    case MenuAccion::TP:
    case MenuAccion::CURAR:
    case MenuAccion::CAMBIAR_TIEMPO:
    case MenuAccion::INTERCAMBIAR:
    case MenuAccion::ENCARCELAR:
    case MenuAccion::VASO_DE_AGUA:
        return true;

    default:
        return false;
    }
}



void MenuHechizos::recolocarSeleccion()
{
    botones[seleccionado].cambiarEstado();

    unsigned int intentos = 0;
    while (botones[seleccionado].estaDesactivo() && intentos < botones.size()) {
        seleccionado++;

        if (seleccionado >= botones.size()) {
            seleccionado = 0;
        }
        intentos++;
    }

    if (!botones[seleccionado].estaDesactivo()) {
        botones[seleccionado].cambiarEstado();
    }
}
