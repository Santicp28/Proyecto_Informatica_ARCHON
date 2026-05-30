#pragma once
#include "ETSIDI.h"


struct Grafsfx {
    const char* ruta;
    void play() const { ETSIDI::play(ruta); }
};

struct Grafmusica {
    const char* ruta;
    void play(bool repite = true) const { ETSIDI::playMusica(ruta, repite); }
    void stop()                   const { ETSIDI::stopMusica(); }
};

inline constexpr Grafsfx sfx_grito_banshee{ "assets/Sonidos/grito_banshee.wav" };
inline constexpr Grafsfx sfx_ataque_fuego{ "assets/Sonidos/ataque_fuego.wav" };
inline constexpr Grafsfx sfx_ataque_disparo{ "assets/Sonidos/ataque_disparo.wav" };
inline constexpr Grafsfx sfx_ataque_explosion{ "assets/Sonidos/ataque_explosion.wav" };
inline constexpr Grafsfx sfx_ataque_melee{ "assets/Sonidos/ataque_melee.wav" };
inline constexpr Grafsfx sfx_muerte{ "assets/Sonidos/muerte.mp3" };
inline constexpr Grafsfx sfx_recibir_danio{ "assets/Sonidos/recibir_danio.mp3" };
inline constexpr Grafmusica musica_fondo{ "assets/Sonidos/musica_fondo.mp3" };