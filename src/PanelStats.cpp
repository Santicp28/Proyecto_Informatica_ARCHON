#pragma once
#include "PanelStats.h"
#include <string>

void PanelStats::dibuja(const Renderer& renderer) const
{
    /*char debug[50];
    std::snprintf(debug, sizeof(debug), "W:%d H:%d", Config::anchoVentana, Config::altoVentana);
    renderer.dibujaTexto(debug, { posicion.x, posicion.y - 20 }, { 1,0,0 }, 14, AlineacionTexto::IZQUIERDA);*/


    float referencia = (glutGet(GLUT_WINDOW_WIDTH) + glutGet(GLUT_WINDOW_HEIGHT)) * 0.5f;
    tamTexto = static_cast<int>(referencia * 0.011f);
    tamTitulo = static_cast<int>(referencia * 0.02f);

 

	Vector2D centro = { posicion.x + size.x / 2.0, posicion.y + size.y / 2.0 };

    double salto = 17;

    double x_texto = posicion.x ;
    double y_texto_inicio = posicion.y + 45;


	renderer.dibujaSprite(panel.sprite, centro, size.x * 2.2, size.y * 1.3); //Fondo con textura
   // renderer.dibujaCuadrado(centro, colorFondo, size); //Fondo
    renderer.dibujaContornoCuadrado(centro, colorBorde, size); //Bordes
    
   renderer.dibujaTexto(titulo, {x_texto, posicion.y + 30}, colorTitulo, tamTitulo, AlineacionTexto::IZQUIERDA); //Título

    double y_stats = y_texto_inicio + 2;
    
	if (pieza != nullptr) {
        renderer.dibujaTexto(pieza->getNombre(), {x_texto, y_texto_inicio}, colorTexto, tamTexto, AlineacionTexto::IZQUIERDA);
        dibujaLineaStat(renderer, "Vida Actual", pieza->getVidaActual(), { x_texto, y_stats + salto });
		dibujaLineaStat(renderer, "Vida Max.", pieza->getVidaMax(), { x_texto, y_stats + 2 * salto });
        dibujaLineaStat(renderer, "Ataque", pieza->getAtaque(), { x_texto, y_stats + 3 * salto });
        dibujaLineaStat(renderer, "Defensa", pieza->getDefensa(), { x_texto, y_stats + 4 * salto });
        dibujaLineaStat(renderer, "Velocidad", pieza->getVelocidad(), { x_texto, y_stats + 5 * salto });
		dibujaLineaStat(renderer, "Cadencia", pieza->getCadencia(), { x_texto, y_stats + 6 * salto });
		dibujaLineaStat(renderer, "Vel. At.", pieza->getVelocidadAtaque(), { x_texto, y_stats + 7 * salto });
		renderer.dibujaTexto("Mov.: " + pieza->getTipoMovimientoString(), { x_texto, y_stats + 8 * salto }, colorTexto, tamTexto, AlineacionTexto::IZQUIERDA);
        dibujaLineaStat(renderer, "Rango", pieza->getRangoMovimiento(), { x_texto, y_stats + 9 * salto });
    }
    
}

void PanelStats::dibujaLineaStat(const Renderer& renderer, const char* nombre, double valor, Vector2D posicionTexto) const
{
    char texto[30];

    std::snprintf(texto, sizeof(texto), "%s: %.2f", nombre, valor);

	renderer.dibujaTexto(texto, posicionTexto, colorTexto, tamTexto, AlineacionTexto::IZQUIERDA);
}