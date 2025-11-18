#ifndef GLOBAL_DEFINITIONS
#define GLOBAL_DEFINITIONS
#include "raylib.h"

// ----- GLOBAL VARIABLES -----
#define SCREEN_WIDTH 400
#define SCREEN_HEIGHT 800
extern int points;
extern int lives;

// ----- GLOBAL FUNCTIONS -----
void movements(float &ft);

void collisions();

void draw();

void initializeGame();

#endif