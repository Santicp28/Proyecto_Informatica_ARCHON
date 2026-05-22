#pragma once
#include "freeglut.h"

class VisualBoard {
private:
    float cellSize;
    int gridSize;
    int layout[9][9]; // Los datos ahora viven aquí

public:
    VisualBoard(float cSize = 1.0f); // Simplificamos el constructor
    void draw(); // Ya no necesita recibir la matriz cada vez

private:
    void setTileColor(int type);
};