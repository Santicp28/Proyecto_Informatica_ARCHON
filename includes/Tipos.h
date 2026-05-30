#pragma once

constexpr int TAM_TABLERO = 9;

enum class MenuAccion
{
    NINGUNA,
    SALIR,

    JUGAR,
    OPCIONES,
    
    TP,
    CURAR,
    CAMBIAR_TIEMPO,
    INTERCAMBIAR,
    ENCARCELAR,
    VASO_DE_AGUA,

    CONTINUAR,

	IR_MENU_PRINCIPAL
};

enum class TableroAccion {
	NINGUNA,

    IR_PAUSA,
    IR_ARENA,
	IR_FIN_PARTIDA
};

enum class Bando {
    NINGUNO,
    AZUL,
    ROJO
};

enum class TipoCasilla {
    AZUL,
    TURQUESA,
    VERDE,
    AMARILLA,
    NARANJA,
    ROJA,
    OSCILANTE,
    PODER,
};

enum class TipoPieza
{
    ARQUERO,
    BANSHEE,
    BASILISCO,
    CABALLERO,
    CAMBIAFORMA,
    DJINNI,
    DRAGON,
    DUENDE,
    FENIX,
    GOLEM,
    HECHICERO,
    MAGO,
    MANTICORA,
    TROL,
    UNICORNIO,
    VALQUIRIA
};

enum class TipoMovimiento {
    CAMINA,
    VUELA,
    TELETRANSPORTE
};


enum class Cadencia {
    VARIABLE,
    MUYRAPIDA,
    RAPIDA,
    PROMEDIO,
    LENTA
};
enum class Velocidad {
    VARIABLE,
    NORMAL,
    BAJA
};
enum class Vida_maxima {
    VARIABLE,
    MUYALTA,
    ALTA,
    MODERADA,
    CORTA,

};
enum class Ataque {
    VARIABLE,
    MUYALTO,
    ALTO,
    MODERADO,
    BAJO
};
enum class Velocidad_ataque {
    VARIABLE,
    INSTANTANEO,
    RAPIDO,
    NORMAL,
    LENTO
};

enum class Rango {
    CORTO,
    MEDIO,
    LARGO
};

struct PosicionMatriz {
    int fila;
    int columna;

    bool operator==(const PosicionMatriz& p) const {
        return fila == p.fila && columna == p.columna;
    }
};

// PARA SABER QUE ATAQUE USAMOS
enum class TipoAtaque {
    MELEE,      // daño puntual al tocar (knight, goblin)
    AREA,       // daño continuo en radio alrededor (banshee, phoenix)
    PROYECTIL   // dispara un objeto que viaja (wizard, archer, unicorn)
};

enum class AlineacionTexto {
	CENTRADO,
	IZQUIERDA
};

struct CicloAZUL_A_ROJO {
    bool valor;
};