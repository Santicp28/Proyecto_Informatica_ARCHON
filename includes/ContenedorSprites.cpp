#include "ContenedorSprites.h"

void ContenedorSprites::cargarContenedorSprites()
{
	spriteMenu = make_unique<Sprite>("assets/Graficos/menu.png");

	spriteFondotablero = make_unique<Sprite>("assets/Graficos/fondo.png");
	spriteMesa = make_unique<Sprite>("assets/Graficos/mesa.png");
	spriteHoja = make_unique<Sprite>("assets/Graficos/hoja.png");
	spriteClara = make_unique<Sprite>("assets/Graficos/casilla_azul.png");
	spriteBastanteClara = make_unique<Sprite>("assets/Graficos/casilla_turquesa.png");
	spriteLigeramenteClara = make_unique<Sprite>("assets/Graficos/casilla_verde.png");
	spriteLigeramenteOscura = make_unique<Sprite>("assets/Graficos/casilla_amarilla.png");
	spriteBastanteOscura = make_unique<Sprite>("assets/Graficos/casilla_naranja.png");
	spriteOscura = make_unique<Sprite>("assets/Graficos/casilla_roja.png");
	spriteElegido = make_unique<Sprite>("assets/Graficos/elegido.png");
	spritePosiciones = make_unique<Sprite>("assets/Graficos/posiciones.png");
	spriteCursor = make_unique<Sprite>("assets/Graficos/Cursor.png");
	spriteCursorLuz = make_unique<Sprite>("assets/Graficos/cursor_luz.PNG");
	spriteCursorOscuro = make_unique<Sprite>("assets/Graficos/cursor_osc.PNG");
	spriteCasillaEspecial = make_unique<Sprite>("assets/Graficos/casillas especial.PNG");

	spriteCancelar = make_unique<Sprite>("assets/Graficos/cease.png");
	spriteElementos = make_unique<Sprite>("assets/Graficos/elemental.png");
	spriteIntercambio = make_unique<Sprite>("assets/Graficos/exchange.png");
	spriteExplosion = make_unique<Sprite>("assets/Graficos/explosion.png");
	spriteCurar = make_unique<Sprite>("assets/Graficos/heal.png");
	spriteRevivir = make_unique<Sprite>("assets/Graficos/revive.png");
	spriteTiempo = make_unique<Sprite>("assets/Graficos/shifttime.png");
	spriteTeletransportar = make_unique<Sprite>("assets/Graficos/teleport.png");

	spriteArena= make_unique<Sprite>("assets/Graficos/arena.png");

	spriteMago.spriteCuerpo = make_unique<Sprite>("assets/Graficos/mago.png");
	spriteMago.spriteAtaque = make_unique<Sprite>("assets/Graficos/bolafuego.PNG");
	spriteUnicornio.spriteCuerpo = make_unique<Sprite>("assets/Graficos/unicornio.png");
	spriteUnicornio.spriteAtaque = make_unique<Sprite>("assets/Graficos/rayo.PNG");
	spriteArquero.spriteCuerpo = make_unique<Sprite>("assets/Graficos/arquero.png");
	spriteArquero.spriteAtaque = make_unique<Sprite>("assets/Graficos/flecha.PNG");
	spriteGolem.spriteCuerpo = make_unique<Sprite>("assets/Graficos/golem.PNG");
	spriteGolem.spriteAtaque = make_unique<Sprite>("assets/Graficos/rocas.PNG");
	spriteValquiria.spriteCuerpo = make_unique<Sprite>("assets/Graficos/valquiria.png");
	spriteValquiria.spriteAtaque = make_unique<Sprite>("assets/Graficos/lanza.png");
	spriteDjinni.spriteCuerpo = make_unique<Sprite>("assets/Graficos/djinni.png");
	spriteDjinni.spriteAtaque = make_unique<Sprite>("assets/Graficos/tornado.PNG");
	spriteFenix.spriteCuerpo = make_unique<Sprite>("assets/Graficos/fenix.PNG");
	spriteFenix.spriteAtaque = make_unique<Sprite>("assets/Graficos/explosion.PNG");
	spriteCaballero.spriteCuerpo = make_unique<Sprite>("assets/Graficos/caballero.png");
	spriteCaballero.spriteAtaque = make_unique<Sprite>("assets/Graficos/espada.PNG");
	spriteHechicero.spriteCuerpo = make_unique<Sprite>("assets/Graficos/hechicero.png");
	spriteHechicero.spriteAtaque = make_unique<Sprite>("assets/Graficos/hazluz.PNG");
	spriteBasilisco.spriteCuerpo = make_unique<Sprite>("assets/Graficos/basilisco.png");
	spriteBasilisco.spriteAtaque = make_unique<Sprite>("assets/Graficos/laser.PNG");
	spriteManticora.spriteCuerpo = make_unique<Sprite>("assets/Graficos/manticora.png");
	spriteManticora.spriteAtaque = make_unique<Sprite>("assets/Graficos/pinchos.PNG");
	spriteTrol.spriteCuerpo = make_unique<Sprite>("assets/Graficos/trol.PNG");
	spriteTrol.spriteAtaque = make_unique<Sprite>("assets/Graficos/piedras.PNG");
	spriteBanshee.spriteCuerpo = make_unique<Sprite>("assets/Graficos/banshee.png");
	spriteBanshee.spriteAtaque = make_unique<Sprite>("assets/Graficos/grito.PNG");
	spriteCambiaforma.spriteCuerpo = make_unique<Sprite>("assets/Graficos/cambiaformas.png");
	spriteCambiaforma.spriteAtaque = make_unique<Sprite>("assets/Graficos/garrote.PNG");
	spriteDragon.spriteCuerpo = make_unique<Sprite>("assets/Graficos/dragon.PNG");
	spriteDragon.spriteAtaque = make_unique<Sprite>("assets/Graficos/fuego.PNG");
	spriteDuende.spriteCuerpo = make_unique<Sprite>("assets/Graficos/duende.png");
	spriteDuende.spriteAtaque = make_unique<Sprite>("assets/Graficos/garrote.PNG");
}

void ContenedorSprites::descargarContenedorSprites()//destruir el objeto Sprite si existe, liberar memoria, dejar el puntero como nullptr
{
	spriteMenu.reset();

	spriteFondotablero.reset();
	spriteMesa.reset();
	spriteHoja.reset();
	spriteClara.reset();
	spriteBastanteClara.reset();
	spriteLigeramenteClara.reset();
	spriteLigeramenteOscura.reset();
	spriteBastanteOscura.reset();
	spriteOscura.reset();
	spriteElegido.reset();
	spritePosiciones.reset();
	spriteCursor.reset();
	spriteCursorLuz.reset();
	spriteCursorOscuro.reset();
	spriteCasillaEspecial.reset();

	spriteCancelar.reset();
	spriteElementos.reset();
	spriteIntercambio.reset();
	spriteExplosion.reset();
	spriteCurar.reset();
	spriteRevivir.reset();
	spriteTiempo.reset();
	spriteTeletransportar.reset();

	spriteArena.reset();

	spriteMago.reset();
	spriteUnicornio.reset();
	spriteArquero.reset();
	spriteGolem.reset();
	spriteValquiria.reset();
	spriteDjinni.reset();
	spriteFenix.reset();
	spriteCaballero.reset();
	spriteHechicero.reset();
	spriteBasilisco.reset();
	spriteManticora.reset();
	spriteTrol.reset();
	spriteBanshee.reset();
	spriteCambiaforma.reset();
	spriteDragon.reset();
	spriteDuende.reset();
}

void ContenedorSprites::cambiarModo()
{
	cargado = !cargado;
	if (cargado)
		cargarContenedorSprites();
	else
		descargarContenedorSprites();
}
