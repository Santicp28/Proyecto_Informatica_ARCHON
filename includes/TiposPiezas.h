#pragma once
#include "Pieza.h"

// Representación de la Luz (Esfera)
class PiezaEsferica : public Pieza {
public:
    using Pieza::Pieza; // Hereda el constructor

    void dibujar() override {
        float px, py;
        calcularPosicionMundo(px, py);
        glDisable(GL_LIGHTING);
        glPushMatrix();
        glTranslatef(px, py, 0.2f); // Elevamos la pieza sobre el tablero
        glColor3f(1.0f, 0.8f, 0.0f); // Color Oro/Luz
        glutSolidSphere(cellSize * 0.35f, 20, 20);
        glPopMatrix();
        glEnable(GL_LIGHTING);
    }
};

// Representación de la Oscuridad (Cubo)
class PiezaCubica : public Pieza {
public:
    using Pieza::Pieza;

    void dibujar() override {
        float px, py;
        calcularPosicionMundo(px, py);
        glDisable(GL_LIGHTING);
        glPushMatrix();
        glTranslatef(px, py, 0.2f);
        glColor3f(0.1f, 0.5f, 0.0f); // Color Cian/Oscuro
        glutSolidCube(cellSize * 0.6f);
        glPopMatrix();
        glEnable(GL_LIGHTING);
    }
};