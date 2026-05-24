#pragma once

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

struct PosicionMatriz {
    int fila;
    int columna;
};

inline bool operator ==(const PosicionMatriz& a, const PosicionMatriz& b) {
    return a.fila == b.fila && a.columna == b.columna;
}

// PARA SABER QUE ATAQUE USAMOS
enum class TipoAtaque {
    MELEE,      // daño puntual al tocar (knight, goblin)
    AREA,       // daño continuo en radio alrededor (banshee, phoenix)
    PROYECTIL   // dispara un objeto que viaja (wizard, archer, unicorn)
};
