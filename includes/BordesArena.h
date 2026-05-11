#pragma once
#include "Pared.h"
#include "InteraccionArena.h"

class InteraccionArena;

class BordesArena
{
    Pared suelo{ {  50, 50  }, { 750,  50  }, { 100, 80, 30 } };
    Pared techo{ {  50, 550 }, { 750, 550  }, { 100, 80, 30 } };
    Pared izq{ {  50, 50  }, {  50, 550  }, { 100, 80, 30 } };
    Pared dcha{ { 750, 50  }, { 750, 550  }, { 100, 80, 30 } };
public:
    void dibuja() const;
    friend class InteraccionArena;
};

