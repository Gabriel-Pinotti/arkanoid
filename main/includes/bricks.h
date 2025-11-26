#ifndef BRICKS
#define BRICKS
#include "raylib.h"

const int brickRows = 5;
const int bricksPerRow = 5;

struct Brick {
    Vector2 position;
    int health;
    Vector2 size;
};

extern Brick brick[brickRows][bricksPerRow];

void initializeBricks();

void setBricksHealth(int row, int col);

void drawBricks();

#endif