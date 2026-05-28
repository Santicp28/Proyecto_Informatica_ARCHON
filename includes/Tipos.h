#pragma once
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
    TIJERAS,

    CONTINUAR,

	IR_MENU_PRINCIPAL
};

enum class Bando {
    NINGUNO,
    LUZ,
    OSCURIDAD
};

enum class TipoCasilla {
    CLARA,
    BASTANTE_CLARA,
    LIGERAMENTE_CLARA,
    LIGERAMENTE_OSCURA,
    BASTANTE_OSCURA,
    OSCURA,
    OSCILANTE,
    PODER,
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
