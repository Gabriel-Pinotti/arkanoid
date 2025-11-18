#ifndef GLOBAL_DEFINITIONS
#define GLOBAL_DEFINITIONS
#include "raylib.h"

// ----- GLOBAL VARIABLES -----
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 800
const int brickRows = 4;
const int bricksPerRow = 5;

// ----- TEXTURES -----


// ----- STRUCTS -----


struct Brick {
    Vector2 position;
    int health;
    Vector2 size;
};

extern Brick brick[brickRows][bricksPerRow];

#endif