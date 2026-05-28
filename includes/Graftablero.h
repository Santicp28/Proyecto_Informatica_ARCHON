#pragma once
#include "ETSIDI.h"
struct graftablero {
    ETSIDI::Sprite sprite;
};

inline graftablero fondotablero { "assets/Graficos/fondo.png" };
inline graftablero clara { "assets/Graficos/casilla_azul.png" };
inline graftablero bastante_clara { "assets/Graficos/casilla_turquesa.png" };
inline graftablero ligeramente_clara { "assets/Graficos/casilla_verde.png" };
inline graftablero ligeramente_oscura { "assets/Graficos/casilla_amarilla.png" };
inline graftablero bastante_oscura { "assets/Graficos/casilla_naranja.png" };
inline graftablero oscura { "assets/Graficos/casilla_roja.png" };
inline graftablero elegido  { "assets/Graficos/elegido.png" };
inline graftablero posiciones { "assets/Graficos/posiciones.png" };
inline graftablero cursor { "assets/Graficos/Cursor.png" };
inline graftablero cursor_luz { "assets/Graficos/cursor_luz.PNG" };
inline graftablero cursor_oscuro { "assets/Graficos/cursor_osc.PNG" };
inline graftablero casillaespecial { "assets/Graficos/casillas especial.PNG" };
