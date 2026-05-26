#pragma once
enum class MenuAccion
{
    NINGUNA,
    JUGAR,
    OPCIONES,
    SALIR
};
enum class Bando {
    NINGUNO,
    LUZ,
    OSCURIDAD
};

enum class TipoCasilla {
    OSCURA,
    CLARA,
    OSCILANTE,
    PODER,
    INVALIDA
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
enum class Vida {
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
