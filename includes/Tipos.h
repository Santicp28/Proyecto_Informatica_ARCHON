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