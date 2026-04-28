#include "Tablero.h"

VisualBoard::VisualBoard(float cSize) : gridSize(9), cellSize(cSize) {
    // Inicializamos la matriz oficial de Archon una sola vez
    int officialLayout[9][9] = {
        {0, 1, 0, 2, 3, 2, 0, 1, 0},
        {1, 0, 2, 1, 2, 1, 2, 0, 1},
        {0, 2, 1, 0, 2, 0, 1, 2, 0},
        {2, 1, 0, 1, 2, 1, 0, 1, 2},
        {3, 2, 2, 2, 3, 2, 2, 2, 3},
        {2, 1, 0, 1, 2, 1, 0, 1, 2},
        {0, 2, 1, 0, 2, 0, 1, 2, 0},
        {1, 0, 2, 1, 2, 1, 2, 0, 1},
        {0, 1, 0, 2, 3, 2, 0, 1, 0}
    };
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            layout[i][j] = officialLayout[i][j];
}

void VisualBoard::draw() {
    glDisable(GL_LIGHTING); // Desactivar luces para el tablero
    float startPos = -(gridSize * cellSize) / 2.0f;

    for (int row = 0; row < gridSize; ++row) {
        for (int col = 0; col < gridSize; ++col) {
            float x = startPos + col * cellSize;
            float y = startPos + row * cellSize;

            // 1. Dibujar el fondo de la casilla
            setTileColor(layout[row][col]);
            glBegin(GL_QUADS);
            glVertex3f(x, y, 0.0f);
            glVertex3f(x + cellSize, y, 0.0f);
            glVertex3f(x + cellSize, y + cellSize, 0.0f);
            glVertex3f(x, y + cellSize, 0.0f);
            glEnd();

            // 2. Dibujar el borde con un pequeño offset en Z para evitar parpadeo
            glColor3f(1.0f, 0.0f, 0.0f); // Gris oscuro para bordes elegantes
            glLineWidth(2.0f);
            glBegin(GL_LINE_LOOP);
            glVertex3f(x, y, 0.01f);
            glVertex3f(x + cellSize, y, 0.01f);
            glVertex3f(x + cellSize, y + cellSize, 0.01f);
            glVertex3f(x, y + cellSize, 0.01f);
            glEnd();
        }
    }
    glEnable(GL_LIGHTING);
}

void VisualBoard::setTileColor(int type) {
    switch (type) {
    case 0: glColor3f(0.05f, 0.05f, 0.05f); break; // Negro
    case 1: glColor3f(0.95f, 0.95f, 0.95f); break; // Blanco
    case 2: glColor3f(0.50f, 0.50f, 0.50f); break; // Gris (Shifting)
    case 3: glColor3f(0.00f, 0.80f, 0.80f); break; // Cian (Power Point)
    default: glColor3f(0.3f, 0.3f, 0.3f);
    }
}