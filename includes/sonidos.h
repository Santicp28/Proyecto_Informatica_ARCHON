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


inline constexpr Grafsfx sfx_grito_banshee{ "assets/Audios/grito_banshee_low.mp3" };
inline constexpr Grafsfx sfx_ataque_fuego{ "assets/Audios/ataque_fuego.wav" };
inline constexpr Grafsfx sfx_ataque_disparo{ "assets/Audios/ataque_disparo.wav" };
inline constexpr Grafsfx sfx_ataque_explosion{ "assets/Audios/ataque_explosion.wav" };
inline constexpr Grafsfx sfx_ataque_melee{ "assets/Audios/ataque_melee.wav" };
inline constexpr Grafsfx sfx_muerte{ "assets/Audios/muerte.mp3" };
inline constexpr Grafsfx sfx_recibir_danio{ "assets/Audios/recibir_danio.wav" };
inline constexpr Grafmusica musica_fondo{ "assets/Audios/musica_fondo.mp3" };
inline constexpr Grafmusica musica_fondo_suave{ "assets/Audios/musica_fondo_suave.mp3" };