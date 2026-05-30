#pragma once
#include <memory>
#include"ETSIDI.h"
using ETSIDI::Sprite, std::unique_ptr, std::make_unique;

struct SpritePieza
{
	unique_ptr<Sprite> spriteCuerpo;
	unique_ptr<Sprite> spriteAtaque;
	void reset()
	{
		spriteCuerpo.reset();
		spriteAtaque.reset();
	}
};

class ContenedorSprites//equivalente a Sprite* spriteCuerpo= nullptr;
{
	unique_ptr<Sprite> spriteMenu;

	unique_ptr<Sprite> spriteFondotablero;
	unique_ptr<Sprite> spriteMesa;
	unique_ptr<Sprite> spriteHoja;
	unique_ptr<Sprite> spriteClara;
	unique_ptr<Sprite> spriteBastanteClara;
	unique_ptr<Sprite> spriteLigeramenteClara;
	unique_ptr<Sprite> spriteLigeramenteOscura;
	unique_ptr<Sprite> spriteBastanteOscura;
	unique_ptr<Sprite> spriteOscura;
	unique_ptr<Sprite> spriteElegido;
	unique_ptr<Sprite> spritePosiciones;
	unique_ptr<Sprite> spriteCursor;
	unique_ptr<Sprite> spriteCursorLuz;
	unique_ptr<Sprite> spriteCursorOscuro;
	unique_ptr<Sprite> spriteCasillaEspecial;

	unique_ptr<Sprite> spriteCancelar;
	unique_ptr<Sprite> spriteElementos;
	unique_ptr<Sprite> spriteIntercambio;
	unique_ptr<Sprite> spriteExplosion;
	unique_ptr<Sprite> spriteCurar;
	unique_ptr<Sprite> spriteRevivir;
	unique_ptr<Sprite> spriteTiempo;
	unique_ptr<Sprite> spriteTeletransportar;

	unique_ptr<Sprite> spriteArena;

	SpritePieza spriteMago;
	SpritePieza spriteUnicornio;
	SpritePieza spriteArquero;
	SpritePieza spriteGolem;
	SpritePieza spriteValquiria;
	SpritePieza spriteDjinni;
	SpritePieza spriteFenix;
	SpritePieza spriteCaballero;
	SpritePieza spriteHechicero;
	SpritePieza spriteBasilisco;
	SpritePieza spriteManticora;
	SpritePieza spriteTrol;
	SpritePieza spriteBanshee;
	SpritePieza spriteCambiaforma;
	SpritePieza spriteDragon;
	SpritePieza spriteDuende;

public:
	void cargarContenedorSprites();
	void descargarContenedorSprites();
};
