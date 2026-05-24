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

struct PosicionMatriz {
    int fila;
    int columna;
};

inline bool operator ==(const PosicionMatriz& a, const PosicionMatriz& b) {
    return a.fila == b.fila && a.columna == b.columna;
}